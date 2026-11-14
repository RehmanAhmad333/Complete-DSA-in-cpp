#include<iostream>
#include<vector>

using namespace std;

// Node class definition
class Node{
	public:
		int data;     // Value of the current node
		Node* left;   // Pointer to the left child
		Node* right;  // Pointer to the right child
		
		// Constructor to initialize a new node		
		Node(int val){
			data = val;
			left=right=NULL;
		}
};

static int idx=-1;  // Global index to track the current position in the preorder array ,Static ensures it retains its value across recursive calls


// Function: buildTree
// Purpose : Builds a Binary Tree from a given preorder traversal
// Input   : Vector containing preorder sequence where -1 represents NULL
// Output  : Returns pointer to the root node of the constructed tree

Node* bulitTree(vector<int>preorder){
	idx++;   // Move to next element in preorder sequence
	
	//If current element is -1, return NULL (no node)
	if(preorder[idx]== -1){
		return NULL;
	}
	
	Node* root=new Node(preorder[idx]);    // Create new node with current value
	
	
	// Recursively build left and right subtrees
	root->left=bulitTree(preorder);
	root->right=bulitTree(preorder);
	
	return root;  // Return the constructed subtree’s root
}

int main(){
	vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	Node* root=bulitTree(preorder);
		
	cout<<"Root -> "<<root->data<<endl;
	
	return 0;
}



















