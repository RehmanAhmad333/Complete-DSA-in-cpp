#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize the node with data
		Node(int val){
			data=val;
			left=right=NULL;
		}	
};

static int idx=-1;   // static variable to keep track of current index in tree vector

// Function to build binary tree from preorder traversal input
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){   	// If current value is -1, that means there is no node (NULL)
		return NULL;
	} 
	
	// Create a new node with the current value
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;   	// Return the constructed node
}

// Function to count total number of nodes in the tree
int count(Node* root){	
	if(root == NULL){  // Base case: if tree is empty
		return 0;
	}
	
	// Recursively count nodes in left and right subtrees
	int leftCount=count(root->left);
	int rightCount=count(root->right);
	
	return leftCount + rightCount + 1;  // Total nodes = left subtree nodes + right subtree nodes + current node (1)	
}

int main(){
	vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node* root=buildTree(tree);  	// Build the binary tree
	
	cout<<"Root Element: "<<root->data<<endl;
	
	int nodeCount=count(root);   	// Count total number of nodes in the tree
	
	cout<<"Total nodes in tree: "<<nodeCount<<endl;	
	return 0;
}
