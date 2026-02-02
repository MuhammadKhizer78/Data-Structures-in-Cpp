#include<iostream>
using namespace std;

class Queue{
    private:
        int* arr;
        int front;
        int rear;
        int size;
        int no_of_elements;

    public:
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

int main(){
    Queue q(8);
    q.enqueue(19);
    q.enqueue(54);
    q.enqueue(13);
    q.enqueue(61);
    q.enqueue(21);
    q.enqueue(11);
    q.enqueue(41);
    q.enqueue(15);
    cout<<"The value deleted is "<<q.dequeue()<<".\n";
    q.enqueue(16);
    
    q.display();
    
    return 0;
}
