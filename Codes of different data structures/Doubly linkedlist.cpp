//doubly linkedlist
#include <iostream>
using namespace std;

class node{
	public:
		int val;
		node *next;
		node *previous;
		
		node(int v){	
			val=v;
			next=nullptr;
			previous=nullptr;
		}
};

class linkedlist{
	private:
	int length;
	node *head;
	
	public:
	linkedlist(){
		head=nullptr;
		length=0;
	}
	
	void insert(int val,int pos){
		if (pos>length+1||pos<0){
		    cout<<"invalid positioin"<<endl;
				return;
		}
		
		node *n=new node;
		
		if(pos==1){
		n->next=head;
		if(head!=nullptr)
		{head->previous=n;} 
		head=n;
		}
		else{
			node *current=head;
			for(int i=1;(i<pos-1);i++){
				current=current->next;
			}
			
			n->next=current->next;// links the new node to next
			if(current->next!=nullptr)
			{current->next->previous=n;}// connects the previous of n to current next part  // if we insert in end the next of will be null and ->previous will be null also which gives us error
			n->previous=current;// connects the previous part of n to current
			current->next=n;// currents next points to n
			
		 }
		 length++;
		
	}
	
	void remove(int pos){
		if(pos<0||pos>length){
			cout<<"invalid position"<<endl;
			
			return;
			}
		if(head==nullptr){
			cout<<"empty"<<endl;
			
			return;
		}	
              		
		node *current=head;
		
		if (pos==1){		
			head=head->next;// moves head a step ahead
			if(head!=nullptr){ // checks if the new head is not  null means there is/are another nodes   
			head->previous=nullptr;// so its previous becomes nulll as its 1st node now if there is onluy one node and we delete it this will not will and current will delete immediately
			}
			delete current;
		}
		else {	
			for (int i=1;i<pos-1;i++){
				current=current->next;
			}
			node *temp=current->next;// temp points to the node which is to be deleted
			current->next=temp->next;	
			if (temp->next!=nullptr){
				temp->next->previous=current;
			}
			delete temp;
		    }	
	    }			
        }		
    }
};