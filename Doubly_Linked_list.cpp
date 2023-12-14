#include <iostream>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T> *next , *prev;
		
		Node(){
			data = 0;
			next = prev = NULL;
		}
		
		Node(const T& data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
};

template <class T>
class DLinkedList{
	public:
		Node<T> *head , *tail;
		DLinkedList(){
			head = tail = NULL;
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
void DLinkedList<T> :: add_beg(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

template <class T>
void DLinkedList<T>::add_end(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

template <class T>
void DLinkedList<T>::add_pos(const T& el , int pos){
	Node<T> *newNode = new Node<T>(el);
	int size = 0;
	Node<T> * temp = head;
	
	while (temp != NULL){
		size++;
		temp = temp-> next;
	}
	
	if (size+1 >= pos){
		if (pos == 0){
			add_beg(el);
			return;
		}
		
		if (pos == size + 1){
			add_end(el);
			return;
			
		}
		
		else{
			Node<T> *c = head;
			Node<T> *p = NULL;
			for (int i = 0; i< pos; i++){
				p = c;
				c = c->next;
			}
			
			newNode->next = c;
			newNode->prev = p;
			
			p->next = newNode;
			c->prev = newNode;
			
		}
	}
	
	else{
		cout << "Invalid Position !";
		return;
	}
	
}

template <class T>
void DLinkedList<T>::delete_beg(){
	if (head == NULL){
		cout << "Underflow !";
		return;
	}
	Node<T> *temp = head;
	head = head->next;
	
	if (head != NULL)
		head->prev = NULL;
	
	delete(temp);
	
}

template <class T>
void DLinkedList<T>::delete_end(){
	if (head == NULL){
		cout << "Undeflow !";
	}
	
	Node<T> *temp = tail;
	tail = tail-> prev;
	
	if (tail != NULL){
		tail->next = NULL;
	}
	
	delete(temp);
}

template <class T>
void DLinkedList<T>::delete_pos(int pos){
	int size = 0;
	Node<T> *temp = head;
	
	while (temp != NULL){
		size++;
		temp = temp->next;
	}
	
	if (size >= pos){
		if (pos == 1){
			delete_beg();
			return;
		}
		
		if (pos == size){
			delete_end();
			return;
		}
		
		else{
			Node<T> *c , *p , *n;
			c = head;
			p = NULL;
			for (int i = 1 ; i < pos; i++ ){
				p =c;
				c=c->next;
			}
			
			n = c->next;
			
			p->next = n;
			n->prev = p;
			delete(c);
			return;
		}
				
	}
	
	else{
		cout << "Invalid Position !";
	}
	
}

template <class T>
void DLinkedList<T>::display(){
	Node<T> *temp = head;
	
	while (temp != NULL){
		cout << temp->data << " \t ";
		temp = temp->next;
	}
	
	cout << "\n";
}

int main() {
    DLinkedList<int> myDLL;

    myDLL.add_beg(10);
    myDLL.add_beg(20);
    myDLL.add_beg(30);

    myDLL.add_end(40);
    myDLL.add_end(50);

    cout << "Doubly Linked List after adding elements:\n";
    myDLL.display();

    myDLL.add_pos(25, 2);

    cout << "\nDoubly Linked List after adding at a specific position:\n";
    myDLL.display();

    myDLL.delete_beg();
    myDLL.delete_end();
    myDLL.delete_pos(2);

    cout << "\nDoubly Linked List after deletions:\n";
    myDLL.display();

    return 0;
}

