#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T> *next , *prev;
		
		Node(){
			data = 0;
			next =NULL;
			prev = NULL;
		}
		
		Node(const T& data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
};

template <class T>
class QueueLL{
	public:
		Node<T> *front , *rear;
		
		QueueLL(){
			front = NULL;
			rear = NULL;
		}
		
		void enqueue(const T&);
		void dequeue();
		T peek();
		bool IsEmpty();
		void clear();
		void display();
};

template <class T>
bool QueueLL<T>::IsEmpty(){
	if (front == NULL){
		return 1;
	}
	
	else{
		return 0;
	}
}

template <class T>
void QueueLL<T>::enqueue(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (IsEmpty()){
		front = newNode; 
		rear = newNode;
		return;
	}
	
	newNode->prev = rear;
	rear->next = newNode;
	rear = newNode;
}

template <class T>
void QueueLL<T>::dequeue(){

	if (IsEmpty()){
		cout << "Underflow !";
		return;
	}
	
	Node<T> *temp = front;
	Node<T> *temp1 = temp->next;
	
	if (temp1 != NULL){
		temp1->prev = NULL;
		front = temp1;
	}
	
	else{
		front = rear = NULL;
	}
	
	delete(temp);	
}

template <class T>
void QueueLL<T>::clear(){
	while (!IsEmpty()){
		dequeue();
	}
}

template <class T>
T QueueLL<T>::peek(){
	
	if (IsEmpty()) {
        cout << "Queue is Empty";
        return NULL;
    }
	
	return front->data;
}

template <class T>
void QueueLL<T>::display(){
	Node<T> *temp = front;
	
	cout << "\n";
	while (temp != NULL){
		cout << temp->data << "\t";
		temp = temp->next;
	}	
}

int main() {
    QueueLL<int> myQueue;

    for (int i = 1; i <= 5; ++i) {
        myQueue.enqueue(i * 10);
    }

    cout << "Queue after enqueue: ";
    myQueue.display();

    cout << "Peek at the front element: " << myQueue.peek() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Queue after dequeue: ";
    myQueue.display();

    myQueue.clear();

    cout << "Queue after clear: ";
    myQueue.display();

    return 0;
}

