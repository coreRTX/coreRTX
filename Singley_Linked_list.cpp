#include <iostream>
using namespace std;

template <class T>
class Node{
	public:
		int data;
		Node<T> *next;
		
		Node(){
			data = 0;
			next =NULL;
		}
		
		Node(const T& data){
			this->data = data;
			this->next = NULL;
		}
};

template <class T>
class SLinkedList{
	public:
		Node<T> *head;
		
		SLinkedList(){
			head = NULL;
		}
		
		void add_beg(const T&);
		void add_end(const T&);
		void add_pos(const T& , int);
		void delete_beg();
		void delete_end();
		void delete_pos(int);
		void display();
};

template <class T>
void SLinkedList<T>::add_beg(const T& el){
	Node<T> *newNode = new Node<T>(el);
	if (head == NULL){
		head = newNode;
		return;
	}
	
	newNode->next = head;
	head = newNode;
}

template <class T>
void SLinkedList<T>::add_end(const T& el){
	Node<T> *newNode = new Node<T>(el);
	
	if (head == NULL){
		head = newNode;
		return;
	}
	
	Node<T> *temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
}

template <class T>
void SLinkedList<T>::add_pos(const T& el , int pos){
	Node<T> *newNode = new Node<T>(el);
	
	if(head == NULL){
		head = newNode;
		return;
	}
	
	int size = 0;
	Node<T> *temp = head;
	while (temp != NULL){
		size++;
		temp = temp->next;
	}
	
	if (pos <= size + 1){
		
		if (pos == 1){
			add_beg(el);
			return;
		}
		
		if (pos == size + 1){
			add_end(el);
			return;
		}
		
		else{
			Node<T> *cur , *prev;
			cur = head;
			prev = NULL;
			
			for (int i = 1; i<pos; i++){
				prev = cur;
				cur = cur->next;
			}
			
			newNode->next = cur;
			prev->next = newNode;
			return;
		}
	}
	
	else{
		cout << "Invalid Position !";
		return;
	}
}

template <class T>
void SLinkedList<T>::delete_beg(){
	if (head == NULL){
		cout << "Underflow !";
		return;
	}
	Node<T> *temp = head;
	head = head->next;
	delete(temp);
}

template <class T>
void SLinkedList<T>::delete_end(){
	if (head == NULL){
		cout << "Underflow !";
		return;
	}
	
	Node<T> *cur , *prev;
	cur = head;
	prev = NULL;
	
	while (cur->next != NULL){
		prev = cur;
		cur = cur->next;
	}
	
	
	if (prev != NULL){
		prev->next = NULL;
	}
	else{
		head = NULL;
	}
	
	delete(cur);
		
}

template <class T>
void SLinkedList<T>::delete_pos(int pos){
	
	if (head == NULL){
		cout << "Underflow !";
		return;
	}
	
	
	int size = 0;
	Node<T> *temp = head;
	
	while (temp != NULL){
		size++;
		temp = temp->next;
	}
	
	if (pos >0 && pos <= size){
		
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
			cur = head;
			prev = NULL;
			
			for (int i = 1; i < pos ; i++){
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

template <class T>
void SLinkedList<T>::display(){
	Node<T> *temp = head;
	
	cout << "\n";
	while (temp != NULL){
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

int main() {
    SLinkedList<int> myList;

    myList.add_end(1);
    myList.add_end(2);
    myList.add_end(3);
    myList.add_end(4);
    myList.add_end(5);

    cout << "Original List: ";
    myList.display();

    myList.add_pos(100, 3);

    cout << "\nList after adding at position 3: ";
    myList.display();

    myList.delete_beg();

    cout << "\nList after deleting from the beginning: ";
    myList.display();

    myList.delete_end();

    cout << "\nList after deleting from the end: ";
    myList.display();

    myList.delete_pos(2);

    cout << "\nList after deleting from position 2: ";
    myList.display();

    return 0;
}

