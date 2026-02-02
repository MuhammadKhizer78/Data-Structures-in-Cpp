#include <iostream>
using namespace std;

// Node class (represents one element in the stack)
class node {
public:
    int val;       // value of the node
    node *next;    // pointer to the next node

    node(int v) {
        val = v;   // FIXED: assign correctly
        next = nullptr;
    }
};

// Stack class (using linked list)
class stack {
private:
    node *top;     // points to the top node of the stack

public:
    // Constructor
    stack() {
        top = nullptr;
    }

    // Check if stack is empty
    bool isempty() {
        if (top == nullptr) {
            cout << "Underflow — Stack is empty!" << endl;
            return true;
        } else {
            return false;
        }
    }

    // Push function — adds element to top
    void push(int val) {
        node *n = new node(val);  // create new node with given value
        n->next = top;            // new node points to previous top
        top = n;                  // now new node becomes top
        cout << val << " pushed into stack." << endl;
    }

    // Pop function — removes top element
    int pop() {
        if (isempty()) {
            cout << "Cannot pop from empty stack!" << endl;
            return -1;
        }

        int val = top->val;       // get value from top node
        node *temp = top;         // store top node to delete later
        top = top->next;          // move top to next node
        delete temp;              // free memory
        cout << val << " popped from stack." << endl;
        return val;
    }

    // Peek function — view top element
    void peek() {
        if (isempty()) {
            cout << "No top element!" << endl;
        } else {
            cout << "Top element is: " << top->val << endl;
        }
    }

    // Destructor — deletes all remaining nodes
    ~stack() {
        while (top != nullptr) {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();
    s.pop();
    s.peek();

    return 0;
}


