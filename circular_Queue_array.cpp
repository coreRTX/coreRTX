#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear + 1) % size == front;
    }

    bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;    // to maintain cyclic nature
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int element = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;    // to maintain cyclic nature
        } else {
            front++;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the Circular Queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    while (true) {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue \n3. isFull \n4. isEmpty \n5. Display\n0. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;
            case 3:
                if (cq.isFull())
                    cout << "\nQueue is full.\n";
                else
                    cout << "\nQueue is not full.\n";
                break;
            case 4:
                if (cq.isEmpty())
                    cout << "\nQueue is Empty.\n";
                else
                    cout << "\nQueue is not Empty.\n";
                break;
            case 5:
                cq.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
