#include <iostream>
using namespace std;

void towersofhanoi(int start , int end , char source , char auxillary , char destination){
	if (start > end){
		return;
	}
	
	towersofhanoi(start ,end - 1, source , destination , auxillary);
	cout << "Move Disk " << end << " from " << source<< " to " << destination << "\n";
	towersofhanoi(start , end -1 , auxillary , source , destination);
}

int main(){
	towersofhanoi (1 , 5 , 'A' , 'B' , 'C');
	return  0;
}

