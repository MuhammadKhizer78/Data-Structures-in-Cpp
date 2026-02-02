#include<iostream>
#include<string>
using namespace std;

//Don't pay much attention to "struct trunk", "showTrunks" and "printTree" functions.
//Because it is just for the visual representation of tree.

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class Node{
    public:
    int info;
    Node* left;
    Node* right;

    Node(int val){
        info = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* n, int val){
    if (n == NULL){
        return new Node(val);
    }
    if (n->info == val){
        cout<<"Duplicate entered.\n";
        return n;
    }
    else if (val < n->info)
    {
        n->left = insert(n->left, val);
        return n;
    }
    else{
        n->right = insert(n->right, val);
        return n;
    }
}

void deleteTree(Node* root){
    if(root != NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

bool search(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->info == val){
        return true;
    }
    else if(val < root->info){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

Node* deleteNode(Node* n, int val){
	if(n == NULL){
		return n;
	}
	if(val < n->info){
		n->left = deleteNode(n->left, val);
	}
	else if(val > n->info){
		n->right = deleteNode(n->right, val);
	}
	else{
		if(n->left == NULL){
			Node* temp = n->right;
			delete n;
			return temp;
		}
		else if(n->right == NULL){
			Node* temp = n->left;
			delete n;
			return temp;
		}
		
		Node* current = n->right;
		while(current && current->left != NULL){
			current = current->left;
		}
		Node* temp = current;
		n->info = temp->info;
		n->right = deleteNode(n->right, temp->info);
	}
	return n;
}

void inorderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	inorderTraversal(root->left);
	cout<<root->info<<"  ";
	inorderTraversal(root->right);
}

void printTree(Node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 11);

    printTree(root, NULL, false);
    
    if(search(root, 9)){
    	cout<<"The value has been found in the tree.\n";
	}
	else{
		cout<<"The value was not found.\n";
	}
	
	cout<<"The inorder traversal of the tree is: \n"; 
	inorderTraversal(root);
	cout<<endl;
	
	deleteNode(root, 12);
	deleteNode(root, 9);
	printTree(root, NULL, false);
	
    deleteTree(root);

    return 0;
}

