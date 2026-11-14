#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize node with a value
		Node(int val){
			data=val;
			left=right=NULL;
		}	
};

static int idx=-1;     // Static index variable used to keep track of the current position in vector

// Function to build binary tree from given preorder vector
Node* buildTree(vector<int>tree){
	idx++;
	
	// Base case: if -1 found, it means there is no node (NULL)
	if(tree[idx] == -1){
		return NULL;
	} 
	
	// Create a new node for current value
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;    	// Return the constructed node
} 

// Function to find the sum of all nodes in the binary tree
int sum(Node* root){

	if(root == NULL){    	// Base case: if tree is empty, sum is 0
		return 0;
	}
	
	// Recursively find sum of left and right subtrees
	int leftSum=sum(root->left);
	int rightSum=sum(root->right);

	return leftSum + rightSum + root->data;   	// Return total sum (left + right + current node)
}

int main(){
	vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node* root=buildTree(tree);    	// Build the binary tree
	
	cout<<"Root Element: "<<root->data<<endl;
	
	int nodeSum=sum(root);     	// Calculate and print the total sum of all nodes
	
	cout<<"Sum of all nodes in tree: "<<nodeSum<<endl;
	return 0;	
}
