#include<iostream>
#include<vector>

using namespace std;

// Node class represents each node in the binary tree
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize the node
		Node(int val){
			data=val;
			left=right=NULL;
		}
	
};

static int idx=-1;  // Used globally to track position in the preorder array

// Function to build binary tree from a preorder traversal array
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){   	// Base case: -1 means there is no node (NULL)
		return NULL;
	} 
	
	Node* root=new Node(tree[idx]);   	// Create a new node with current value
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root; // Return the root node of current subtree
}

// Function to calculate height of a binary tree
int height(Node* root){

	if(root == NULL){
		return 0;    	// If tree is empty, height is 0
	}
	
	// Recursively calculate height of left and right subtrees
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	
	// Height = max(leftHeight, rightHeight) + 1
	return max(leftHeight ,rightHeight) + 1;
	
}

// Function to calculate diameter of the binary tree
// Diameter = longest path between any two nodes in the tree
int diameter(Node* root){
	
	if(root == NULL){   // Base case: empty tree has diameter 0
		return 0;
	}
	
	// Find diameter of left and right subtrees
	int leftDiameter=diameter(root->left);
	int rightDiameter=diameter(root->right);
	
	int currDiameter=height(root->left) + height(root->right);   	// Diameter passing through the current node
	
	// Maximum of: current diameter, left diameter, or right diameter
	return max(currDiameter , max(leftDiameter , rightDiameter));
}

int main(){
	vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node* root=buildTree(tree);   	// Build the tree from the vector
	
	cout<<"Root Element: "<<root->data<<endl;
	
	cout<<"Diameter is  : "<<diameter(root)<<endl;  	// Print the diameter of the tree
	
}















