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

class node
{
    public:
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

node* parent(node* curr, node* p, node* par)
{
    if(curr == NULL)
        return NULL;

    if (curr == p)
    {
        return par;
    }
    else
    {
        node *t = NULL;
        t = parent(curr->left, p, curr);
        if(t!= NULL)
            return t;
        else
        {
            t = parent(curr->right, p, curr);
            return t;
        }

    }
}

node* sibling(node* root, node* p)
{
    node* par = parent(root, p, NULL);

    if (par->left == p)
        return par->right;
    else 
        return par->left;
}

void deleteTree(node* root)
{
    // if (root == NULL)
    //      return;

    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int getLevel(node *ptr,int val,int level = 0) 
{
   if (ptr == NULL)
      return -1;
   if (ptr->info == val)
      return level;
    int left = getLevel(ptr->left, val, level+1);
    int right = getLevel(ptr->right, val, level+1);

    if (left > right)
        return left;
    else 
        return right;
}

int maxDepth(node* n)  
{  
    if (n == NULL)  
        return -1;  
    else
    {
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void preOrder(node *n)
{
    if(n == NULL)
        return;
    
    cout<<n->info<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}

bool find(node* n, int val){
	if(n == NULL){
		return false;
	}
	if(n->info == val){
		return true;
	}
	bool foundleft = find(n->left, val);
	if(foundleft){
		return foundleft;
	}
	bool foundright = find(n->right, val);
	return foundleft || foundright;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(node *&root, Trunk *prev, bool isRight)
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

int main() {
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(7);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->left->left = new node(6);
    root->left->left->right = new node(1);

    printTree(root, NULL, false);
    
    // Find Parent
    node *n = parent(root, root->right->left, NULL);
    cout<<"Parent is: "<<n->info<<endl;

    // Find sibling
    node *sib = sibling(root, root->right->left); //sibling of 3 (which is 9)
    cout<<"Siblinkg of 3 is: "<<sib->info<<endl;

    // Level of a node
    cout<<"Level of 9: "<<getLevel(root, 9)<<endl;

    // Depth of the tree
    cout<<"Depth of the tree: "<<maxDepth(root)<<endl;
    
    // Finding value in a tree
    if(find(root, 3)){
    	cout<<"The value is present in tree.\n";
	}else{
		cout<<"The value is not present.\n";
	}
    deleteTree(root);

    // Tree Traversals (PreOrder, InOrder, PostOrder) [Start]
    node *order = NULL;
    order = new node(1);
    order->left = new node(2);
    order->right = new node(3);
    order->left->left = new node(4);
    printTree(order, NULL, false);
    preOrder(order);
    cout<<endl;
    inOrder(order);
    cout<<endl;
    postOrder(order);
    // Tree Traversals (PreOrder, InOrder, PostOrder) [End]
    cout<<"\nThe depth of tree is "<<maxDepth(order)<<endl;
    deleteTree(order);
    return 0;
}