#include<iostream>
#include<string>
using namespace std;

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

Node* insert(Node* n, int val, int depth = 0){
    if(n == NULL){
        return new Node(val);
    }
    if(depth % 2 == 0){
        // Even Depth -> Create Right Child
        n->right = insert(n->right, val, depth + 1);
    }
	else{
        // Odd Depth -> Create Left Child
        n->left = insert(n->left, val, depth + 1);
    }
    return n;
}

void deleteTree(Node* root){
    if(root != NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
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
	Node* root = nullptr;
	root = insert(root, 5);
	root = insert(root, 13);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 18);
	root = insert(root, 20);
    
	printTree(root, nullptr, false);
    
    deleteTree(root);
    
    return 0;
}