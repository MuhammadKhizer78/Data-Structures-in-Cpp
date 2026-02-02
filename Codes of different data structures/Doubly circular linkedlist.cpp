// doubly circular linkedlist
#include <iostream>
using namespace std;

class node{
	public:
		int val;
		node *next;
		node *prev;
		
		node(int v){
			val=v;
			next=nullptr;
			prev=nullptr;
		}
};

class linkedlist{
	public:
	node *head;
	int length;
	
	linkedlist(){
		head=nullptr;
		length=0;
	}
	
	void insert(int val,int pos){
		if(pos<1||pos>length+1){
			cout<<"invalid position"<<endl;
			return;
		}
		node *n=new node(val);
		if(head==nullptr){
			head=n;
			n->next=n;
			n->prev=n;
		}
		else if (pos==1){
			node *tail=head->prev;
			n->next=head;
			n->prev=tail;
			tail->next=n;
			head->prev=n;
			head=n;
			
		}
		
		else {
			node *current=head;
			
			for(int i =1;i<pos-1;i++){
				current=current->next;
			}
			n->next=current->next;
			n->prev=current;
			current->next->prev=n;
			current->next=n;
			
			
		}
		length++;
	}
	
	void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

};