#include<iostream>
using namespace std;

// You have to test the programs separately, then it works.

int main(){
	int lab[5] = {3, 4, 7, 5, 3};
	int* p= lab;
	for(int i=0; i<5; i++){
		cout<<*(p+i)<<" ";
	}
	cout<<endl;
	
	float data[6] = {4.1, 3.2, 6.9, 2.1, 1.0, 9.9};
	float* d = data;
	float num, sum = 0;
	for(int i=0; i<6; i++){
		sum = sum + *(d+i);
	}
	cout<<"Enter your number: "; cin>>num;
	//checking
	if(num == sum){cout<<"The number you entered is equal to sum.\n";}
	else{cout<<"The number is not equal to sum.\n "<<sum<<" != "<<num<<"\n";}
	
	int size; 
	int tree[size];
	cout<<"Enter the size of your array: "; 
	cin>>size;
	int *g = tree;
	for(int i=0; i<size; i++){
		//*(g + i) = rand() % 100;
		cin>>*(g+i);
	}
	for(int i=0; i<size; i++){
		cout<<*(g + i)<<" ";
	}
	cout<<endl;
	for(int i=0; i<size; i+=2){
		int temp = *(g + i);
		*(g + i) = *(g + i + 1);
		*(g + i + 1) = temp;
	}
	
	for(int i=0; i<size; i++){
		cout<<*(g+i)<<" ";
	}
	 
    return 0;
}
