#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;        // pointer to the array
    int capacity;    // total size of the stack
    int top;         // index of the top element

public:
    // Constructor
    Stack(int s) {
        capacity = s;         // assign capacity
        arr = new int[s];     // allocate array of size s
        top = -1;             // initialize top to -1 (empty stack)
    }

    // Function to check if stack is full
    bool isFull() {
        if ((top + 1) == capacity) {
            return true;
        } else {
            return false;
        }
    }

    // Push function
    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
        cout << val << " pushed to stack" << endl;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    // Pop function
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1; // return error value
        } else {
            int val = arr[top];
            top--;
            return val;
        }
    }

    // Peek function (returns top element without removing)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};


int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;

    return 0;
}