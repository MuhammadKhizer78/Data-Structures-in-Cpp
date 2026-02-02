#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *next;

    node(int v) {
        val = v;
        next = nullptr;
    }
};

// Stack class (using linked list)
class stack {
private:
    node *top;

public:
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

    ~stack() {
        while (top != nullptr) {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class Queue{
    public:
        int* arr;
        int front;
        int rear;
        int size;
        int no_of_elements;

        Queue(int s){
            arr = new int[s];
            size = s;
            front = 0;
            rear = -1;
            no_of_elements = 0;
        }

        bool isFull(){
            if(no_of_elements == size){
                return true;
            }
            else{
                return false;
            }
        }

        void enqueue(int val){
            if(isFull()){
                cout<<"Queue overflow.\n";
                return;
            }
            if(rear == (size - 1)){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = val;
            no_of_elements++;
        }

        bool isEmpty(){
            if(no_of_elements == 0){
                return true;
            }
            else{
                return false;
            }
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue underflow.\n";
                return -1;
            }
            int val = arr[front];
            if(front == (size - 1)){
                front = 0;
            }
            else{
                front++;
            }
            no_of_elements--;
            return val;
        }
        
        void display(){
            if(isEmpty()){
                cout << "Queue is empty.\n";
                return;
            }

            cout << "Queue elements: ";

            int index = front;
            for(int i = 0; i < no_of_elements; i++){
                cout << arr[index] << " ";
                index = (index + 1) % size;  // circular movement
            }

            cout << endl;
        }
        
        ~Queue(){
        	delete[] arr;
		}
};

void reverseElements(Queue &q, int k){
    stack s;
    int n = q.size;

    for(int i=0; i<k; i++){
        s.push(q.dequeue());
    }

    for(int i=0; i<k; i++){
        q.enqueue(s.pop());
    }
    
    for (int i = 0; i < (n - k); i++) {
        int val = q.dequeue();
        q.enqueue(val);
    }
}

int main(){
	Queue obj(10);
    obj.enqueue(2);
    obj.enqueue(4);
    obj.enqueue(6);
    obj.enqueue(8);
    obj.enqueue(10);

    obj.display();

    reverseElements(obj, 3);
    obj.display();
	
	return 0;
}