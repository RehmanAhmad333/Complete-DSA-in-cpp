#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize a node with given value
		Node(int val){
			data=val;
			left=right=NULL;
		}		
};

// static index variable to keep track of position in vector while building tree
static int idx=-1;

// Function to build binary tree from a preorder traversal vector
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){
		return NULL;
	}
	
	// create a new node with current element
	Node* root=new Node(tree[idx]);
	
	// recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}

//Function to convert the tree into sum tree,Each node's value is replaced by the sum of values of its left and right subtrees
int sumTree(Node*root){
	if(root == NULL){
		return 0;
	}
	
	// recursively calculate left and right subtree sums
	int leftSum=sumTree(root->left);
	int rightSum=sumTree(root->right);
	
	// add both subtree sums to current node’s data
	root->data+=leftSum + rightSum;
	
	return root->data;
}

// Function for preorder traversal (Root -> Left -> Right)
void preorder(Node* root){
	if(root == NULL){
		return ;
	}
	
	cout<<root->data<<" ";
	
	preorder(root->left);
	preorder(root->right);
}

int main(){

	vector<int>tree={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	// build the tree using vector data
	Node* root=buildTree(tree);
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// convert to sum tree
	int treeSum=sumTree(root);
	
	cout << "\nNew tree in which all nodes are replaced by sum of their subtrees:\n";
    preorder(root);
    
    cout << endl;
    return 0;	
}














