#include<iostream>
using namespace std ;
class Queue{
    private:
    int*arr;
    int front ;
    int rear ;
    int capacity ;
    public:
    Queue(int capacity){
        this -> capacity = capacity ;
        front =rear= 0 ;
        arr = new int[capacity];
    }

    int isfull(){
        return rear == capacity ;
    }

    bool isEmpty(){
        return front == rear ;
    } 

    void enqueue(int data ){
        if(rear == capacity){
            cout<<" Queue is Full "<<endl ;
            return;
        }
        arr[rear]=data ;
        rear++ ;           
    }
    int Dequeue(){
        if(front ==rear ){
            cout<<"Queue is Empty"<<endl ;
            return 0 ;
        }
        front ++;
    }
    int peek(){
        if(front == rear ){
            cout<<"Queue is Empty"<<endl ;
            return 0;
        }
        return arr[front];
    }
    void Display(){
        if(rear>front){
            cout<<"Queue Elements :";
            for(int i = front ; i<rear ; i++){
                cout<<arr[i] <<" ";
            }
            cout << endl;           
        }
        else{
            cout<<"Queue is Empty "<<endl ;
            return ;
        }
    }
    ~Queue(){
        delete []arr;
    }

};

int main() {
    int capacity;
    cout << "Enter Queue Capacity: ";
    cin >> capacity;

    Queue q(capacity);

    int choice;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. isFull\n";
        cout << "6. isEmpty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2: {
                int dequeued = q.Dequeue();
                break;
            }
            case 3: {
                int peeked = q.peek();
                break;
            }
            case 4:
                q.Display();
                break;
            case 5:
                if (q.isfull())
                cout << "\nQueue is full.\n";
            else
                cout << "\nQueue is not full.\n";
                break;
            case 6:
                if (q.isEmpty()){
                    cout << "\nQueue is empty!!\n";
                }
                else{
                    cout << "\nQueue is not empty!!\n";
                }
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
