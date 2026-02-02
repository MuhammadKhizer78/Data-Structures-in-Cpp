//singly circular linkedlist
#include <iostream>
using namespace std;

class node{
	public:
		 int val;
		 node *next;
		 
		 node(int v){
		 	val=v;
		 	next=nullptr;
		}
};

class linkedlist{
	public:
		node *head;
		int length;
		
		linkedlist(){
			length=0;
			head=nullptr;
		}
		
	void insert(int value,int pos){
		//making a new node
		node *n= new node(value);
		if(pos<0||pos>length+1){
			cout<<"invalid position"<<endl;
			return;
		}
		
	if(pos==1){
		if(head!=nullptr){
		 node *tail=head;
		 
		 while(tail->next!=head){
		 	tail=tail->next;
		 }
		 tail->next=n;
		 n->next=head;
		 head=n;	
		}
		else{
		head=n;
		n->next=head;}
	}
	else{
		node *current=head;
		
		for(int i=1;(i<pos-1);i++){
			current=current->next;
		}
		n->next=current->next;
		current->next=n;
	}
	length++;
    }
		
	void remove(int pos){
		if(length==0){
			cout<<"empty list"<<endl;
			return;
		}
		if (pos<1||pos>length){
			cout<<"invalid pos"<<endl;
			return;
		}
		
		node *current=head;
		if (pos==1){
			if(head->next!=head){
				node *tail=head;
				
				while(tail->next!=head){
					tail=tail->next;
				}
				head=head->next;
				tail->next=head;
			}
			else{
				head=nullptr;
			}
			
			delete current;
		}
		else{
			node *temp;
			for(int i=1;i<pos-1;i++){
				current=current->next;
			}
			temp=current->next;
			current->next=temp->next;
			
			delete temp;
		}
		length--;
		
	}
	
	
	void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    node *current = head;
    do {
        cout << current->val << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

	
};

int main(){	
	linkedlist list1;
	
	list1.insert(3,1);
	list1.insert(4,2);
	list1.insert(5,3);
	list1.insert(6,4);
	list1.insert(7,5);
	list1.insert(8,6);
	
	list1.remove(1);
	list1.remove(4);
	list1.remove(3);
	
	list1.display();
	
	return 0;	
}