#include<iostream>
#include<cmath>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data = val;
			right = NULL;
			left = NULL;
		}
};

int checkAVL(Node* root, bool &isAVL){
	if(root == NULL){
		return 0;
	}
	
	int leftHeight = checkAVL(root->left, isAVL);
	int rightHeight = checkAVL(root->right, isAVL);
	
	int largerHeight;
	if(leftHeight > rightHeight){
		largerHeight = leftHeight;
	}
	else{
		largerHeight = rightHeight;
	}
	
	// Check balance factor
	if(abs(leftHeight - rightHeight) > 1){
		isAVL = false;
	}
	
	largerHeight += 1;
	
	return largerHeight;
}

bool isAVL(Node* root){
	bool ok = true;
	checkAVL(root, ok);
	return ok;
}

int main(){
	Node* root = new Node(4);
	root->left = new Node(6);
	root->right = new Node(8);
	root->right->right = new Node(11);
	
	if(isAVL(root)){
		cout<<"The tree is AVL.\n";
	}else{
		cout<<"The tree is not AVL.\n";
	}
	
	return 0;
}