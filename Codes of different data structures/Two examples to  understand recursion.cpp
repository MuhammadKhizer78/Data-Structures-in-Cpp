#include<iostream>
using namespace std;

// Recursion examples;

int factorial(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	
	return n * factorial(n - 1);
}

int fibonnaci_series(int n){
	if(n == 0 || n == 1){
		return n;
	}
	
	return fibonnaci_series(n - 1) + fibonnaci_series(n - 2);
}

int main(){
    cout<<"The factorial of 6 is "<<factorial(6)<<".\n";
	
	cout<<"The 7th number at fibonnaci series is "<<fibonnaci_series(7)<<".\n";
	
	return 0;
}