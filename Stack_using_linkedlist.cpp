# include <iostream>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T> *next , *prev;
		
		Node(){
			data = 0;
			next = NULL;
			prev = NULL;
		}
		
		Node(const T& data){
			this->data= data;
			this->next = NULL;
			this->prev = NULL;
		}
};

template <class T>
class LStack{
	public:
		Node<T> *top , *head;
		
		LStack(){
			top = NULL;
			head = NULL;
		}
		
		bool IsEmpty();
		void push(const T&);
		void pop();
		void peek();
		void clear();
};

template <class T>
bool LStack<T>::IsEmpty(){
	if (top == NULL){
		return true;
	}
	
	else{
		return false;
	}
	
}

template <class T>
void LStack<T>::push(const T& el){
	Node<T> *newNode = new Node<T>(el);
	if (IsEmpty()){
		head = top = newNode;
		return;
	}
	
	top->next = newNode;
	newNode->prev = top;
	top = newNode;
}

template <class T>
void LStack<T>::pop(){
	if (IsEmpty()){
		cout << "Underflow !";
		return;
	}
	
	Node<T> *temp = top;
	top = top->prev;
	
	if (top != NULL){
		top->next = NULL;
	}
	
	else{
		head = NULL;
		top = NULL;
	}
	
	delete(temp);
	
	
}

template <class T>
void LStack<T>::peek(){
	cout << top->data << "\n";
}

template <class T>
void LStack<T>::clear(){

	while (top != NULL){
		pop();
	}
	
}

int main() {
    LStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: ";
    stack.peek();

    stack.pop();

    cout << "Top element after pop: ";
    stack.peek();

    stack.clear();

    if (stack.IsEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    return 0;
}

