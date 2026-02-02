#include<iostream>
using namespace std;

class ArrayList{
	private:
		int* arr;
		int length;
		int capacity;
		int* current;
	public:
		ArrayList(int s){
			arr = new int[s];
			capacity = s;
			length = 0;
			current = nullptr;
		}
		
		void start(){
			current = arr;
		}
		void next(){
			current++;
		}
		
		void back(){
			current--;
		}
		
		void end(){
			current = arr + length - 1;
		}
		
		~ArrayList(){
			delete []arr;
		}
		
		void insert(int val, int pos){
			if(length == capacity){
				cout<<"Array is full.\n";
			    return;
			}
			if(pos < 1 || pos > (length + 1)){
				cout<<"Invalid position.\n";
				return;
			}
			end();
			for(int i = length; i >= pos; i--){ // A check for insertion between elements
				*(current + 1) = *current;
				back();
			}
			*(current + 1) = val;
			length++;
		}
		
		void remove_by_pos(int pos){
			if(length == 0){
				return;
			}
			if(pos < 1 || pos > length){
				return;
			}
			current = arr + pos - 1;
			for(int i = pos; i < length; i++){
				*current = *(current + 1);
				next();
			}
			length--;
		}
		
		int get(int pos){
			if(length == 0){
				return -1;
			}
			if(pos < 1 || pos > length){
				return -1;
			}
			current = arr + pos - 1;
			return *current;
		}
		
		int update(int val, int pos){
			if(length == 0){
				return -1;
			}
			if(pos < 1 || pos > length){
				return -1;
			}
			current = arr + pos - 1;
			*current = val;
		}
		
		int getLength(){
			return length;
		}
		
		int clear(){
			length = 0;
		}
		
		bool find(int val){
			if(length == 0){
				return 0;
			}
			start();
			for(int i = 0; i < length; i++){
				if(*current == val){
					return i;
				}
				next();
			}
			return false;
		}
		
		void remove_by_val(int val){
			int pos = find(val);
			if(pos != 0){
				remove_by_pos(pos);
			}
			else{
				cout<<"Value is not on the list.\n";
			}
		}
		
		void copy(ArrayList l){
			if(l.getLength() == 0){
				if(length == 0){
					return;
				}				
			}
			for(int i = 1; i <= l.getLength(); i++){
					int val = l.get(i);
					insert(val, i);
				}
		}
};

int main(){
	ArrayList list_1(6);
	list_1.insert(5, 1);
	list_1.insert(8, 2);
	list_1.insert(2, 3);
	list_1.insert(13, 4);
	list_1.insert(29, 5);
	list_1.insert(8, 6);
	
	for(int i = 1; i <= list_1.getLength(); i++){
		cout<<"Element "<<i<<": "<<list_1.get(i)<<endl;
	}
	cout<<endl;
	
	cout<<"Length of the list is "<<list_1.getLength()<<".\n\n";
	
	if(list_1.find(13) == 0){
		cout<<"The value is not present there.\n";
	}
	else{
		cout<<"The value is present.\n";
	}
		
	list_1.update(14, 4);
	list_1.remove_by_pos(6);
	list_1.remove_by_val(29);
	
	for(int i = 1; i <= list_1.getLength(); i++){
		cout<<"Element "<<i<<": "<<list_1.get(i)<<endl;
	}
	cout<<endl;
	
	ArrayList list_2(8);
	list_2.copy(list_1);
	for(int i = 1; i <= list_2.getLength(); i++){
		cout<<"Element "<<i<<": "<<list_2.get(i)<<endl;
	}
	
    return 0;
}