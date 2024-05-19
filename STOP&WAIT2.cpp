#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TIMEOUT 5
#define MAX_SEQ 1
#define TOT_PACKETS 3

#define inc(k) if(k<MAX_SEQ) k++; else k=0;

typedef struct
{
	int data;
}packet;

typedef struct
{
	int seq;
	int ack;
	packet info;
	int err;
}frame;

frame DATA;

typedef enum{frame_arrival,err,timeout,no_event} event_type;

void from_network_layer(packet *);
void to_network_layer(packet *);
void to_physical_layer(frame *);
void from_physical_layer(frame *);
void wait_for_event_sender(event_type *);
void wait_for_event_receiver(event_type *);
void receiver();
void sender();

int i=1;			//Data to be sent by the sender
char turn;			//r ,s
int DISCONNECT=0;

int main()
{
	while(!DISCONNECT)
	{
		sender();
		
		for(long int i=0; i<1000000;i++);	//Delay
		
		receiver();
	}
	return 0;
}

void sender()
{
	static int Sn=0;
	static frame s;
	packet buffer;
	event_type event;
	static int flag=0;
	
	if(flag == 0 )
	{
		from_network_layer(&buffer);
		s.info = buffer;
		s.seq = Sn;
		printf("\n\t\tSENDER : Info = %d	seq No = %d		",s.info,s.seq);
		turn = 'r';
		to_physical_layer(&s);
		flag=1;					// wait for the ACK	
	}
	wait_for_event_sender(&event);
	if(turn=='s')
	{
		if(event == frame_arrival)
		{
			from_network_layer(&buffer);
			inc(Sn);
			s.info = buffer;
			s.seq = Sn;
			printf("\tSENDER : Info = %d	seq No = %d		",s.info,s.seq);
			turn = 'r';
			to_physical_layer(&s);
		}
		if(event == timeout)
		{
			printf("\t\tSENDER : Resending Frame				");
			turn = 'r';
			to_physical_layer(&s);
		}
	}
}

void receiver()
{
	static int Rn=0;
	frame fr,fs;
	event_type event;
	
	wait_for_event_receiver(&event);
	if(turn=='r')
	{
		if(event==frame_arrival)
		{
			from_physical_layer(&fr);
			if(fr.seq==Rn)
			{
				to_network_layer(&fr.info);
				inc(Rn);
			}
			else
				printf("\tRECEIVER : Duplicate Frame Acknowledgement Resent\n");
			
			turn='s';	
			to_physical_layer(&fs);
		}	
		if(event==err)
		{
			printf("\tRECEIVER : Corrupted Frame\n\n");
			turn='s';	//if frame not received sender should sent it again!
		}
	}	
}

void from_network_layer(packet *buffer)
{
	(*buffer).data = i;
	i++;
}

void to_physical_layer(frame *s)
{
	s->err = rand() % 2; //if its 0 means error else non zero means no error
	printf("\nError rate=%d",s->err);
	DATA= *s;
}

void to_network_layer(packet *buffer)
{
	printf("\tRECEIVER : Packet %d received , ACK Sent \n", (*buffer).data);
	if(i>TOT_PACKETS)		//if all packets received then disconnect
	{
		DISCONNECT = 1;
		printf("\nDISCONNECTED");
	}	
} 

void from_physical_layer(frame *buffer)
{
	*buffer = DATA;
}

void wait_for_event_sender(event_type * e)
{
	static int timer=0;
	
	if(turn=='s')
	{
		timer++;
		if(timer==TIMEOUT)
		{
			*e = timeout;
			printf("\t\tSENDER : Ack not received=> TIMEOUT\n\n");
			timer = 0;
			return;
		}
		if(DATA.err==0)
		{
			*e=err;
		}
		else
		{
			timer=0;
			*e= frame_arrival;
		}
	}
}

void wait_for_event_receiver(event_type * e)
{
	if(turn == 'r')
	{
		if(DATA.err==0)
			*e = err;
		else
			*e = frame_arrival;
	}
}
