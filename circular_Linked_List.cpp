#include <iostream>
using namespace std;

template <class T>
class Node{
			
	public:
		T data;
		Node<T>* next;

		Node(){
			data = 0;
			next = NULL;
		}
		
		Node(const T& data){
			this -> data = data;
			this -> next = NULL;
		}
};

template <class T>
class CircularLinkedList{
	public:
		Node<T> * tail;
		
		CircularLinkedList(){
			tail = NULL;
		}
		
		void add_beg(const T&);
		void add_end(const T&);
		void add_pos(const T&, int);
		void delete_beg();
		void delete_end();
		void delete_pos(int);
		void display();
};

template <class T>
void CircularLinkedList<T> :: add_beg(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (tail == NULL){
		tail = newNode;
		newNode->next = newNode;
		return;
	}
	
	newNode->next = tail->next;
	tail->next = newNode;
	
}

template <class T>
void CircularLinkedList<T> :: add_end(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (tail == NULL){
		tail = newNode;
		newNode->next = newNode;
		return;
	}
	
	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
}

template <class T>
void CircularLinkedList<T> :: add_pos(const T& el , int pos){
	Node<T> *newNode = new Node<T>(el);
	int size = 0;
	Node<T> *temp = tail->next;
	
	do{
		size ++;
		temp = temp->next;}
	
	while (temp != temp->next);
	
	if ( pos <= size){
		if (pos == 1){
			add_beg(el);
			return;
		}
		
		if (pos == size){
			add_end(el);
			return;
		}
		
		else{
			Node<T> *cur , *prev;
			cur = tail->next;
			prev = NULL;
			
			for (int i = 1; i < pos; i++){
				prev = cur;
				cur = cur->next;
			}
			
			newNode->next = cur;
			prev->next = newNode;
			return;
			
		}
	}
	else{
		cout << "Invalid position!";
	}
	
	}

template <class T>	
void CircularLinkedList<T>::display(){
	Node<T> *temp = tail->next;
	
	do{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	while (temp != tail->next );
}

template <class T>
void CircularLinkedList<T>::delete_beg(){
	if (tail == NULL){
		cout << "Underflow !";
		return;
	}
	
	Node<T> *temp = tail->next;
	tail->next = temp->next;
	delete(temp);
}

template <class T>
void CircularLinkedList<T>::delete_end(){
	if (tail == NULL){
		cout << "Underflow !";
		return;
	}
	
	Node<T> *temp = tail->next;
	Node<T> *temp1 = tail;
	
	while (temp -> next != tail){
		temp = temp->next;
	}
	
	temp->next = tail->next;
	tail = temp;
	delete(temp1);
}

template <class T>
void CircularLinkedList<T>::delete_pos(int pos){
	
	int size = 0;
	Node<T> *temp = tail->next;
	
	do{
		size ++;
		temp = temp->next;}
	
	while (temp != temp->next);
	
	if ( pos <= size){
		if (pos == 1){
			delete_beg();
			return;
		}
		
		if (pos == size){
			delete_end();
			return;
		}
		
		else{
			Node<T> *cur , *prev;
			cur =tail->next;
			prev = NULL;
			
			for (int i= 0 ; i < pos ; i++){
				prev = cur;
				cur = cur->next;
			}
			
			prev->next = cur->next;
			delete(cur);
			
		}
	}
	
	else{
		cout << "Invalid Position !";
	}
	
}

int main() {
    CircularLinkedList<int> myList;

    myList.add_end(1);
    myList.add_end(2);
    myList.add_end(3);

    myList.display();

    myList.delete_beg();
    myList.display();

    myList.delete_end();
    myList.display();

    myList.delete_pos(1);
    myList.display();

    return 0;
}

