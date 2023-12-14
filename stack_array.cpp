#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        arr = new int[capacity];
    }

    void push(int data) {
        if (top == capacity - 1) {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop() {
        if (top == -1) {
            cout << "Underflow" << endl;
            return -1;
        }
       top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack stack(capacity);

    int choice;
    while (true) {
        cout << "\nStack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Size" << endl;
        cout << "7. Display Stack " << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                stack.pop();
                break;
            }
            case 3: {
                int topValue = stack.peek();
                break;
            }
            case 4: {
                bool empty = stack.isEmpty();
                cout << (empty ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            }
            case 5: {
                bool full = stack.isFull();
                cout << (full ? "Stack is full." : "Stack is not full.") << endl;
                break;
            }
            case 6: {
                int stackSize = stack.size();
                cout << "Stack size: " << stackSize << endl;
                break;
            }
            case 7: {
                stack.display();
                break;
            }
            case 8: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
