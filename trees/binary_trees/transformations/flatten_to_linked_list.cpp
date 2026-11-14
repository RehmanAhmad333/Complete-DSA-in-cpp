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

class Solution{
	public:
		Node* nextRight=NULL;   // Pointer to keep track of next node in the flattened list
		
		// Function to flatten the binary tree into a linked list (in-place)
		void flatten(Node* root){
			if(root == NULL){
				return ;
			}
			
			// Recursively flatten the right and left subtrees
			flatten(root->right);
			flatten(root->left);
			
			// Set left pointer to NULL (since we're making a linked list)
			root->left = NULL;
			
			// Link the right pointer to previously processed node
			root->right = nextRight;
			
			// Move nextRight pointer to current node
			nextRight=root;
		}
		
		// Function to print the flattened linked list
		void print(){
			Node* temp =nextRight;
			cout<<"\nFlatten Binary Tree to Linked List : \n\t\t\t\t     ";
			while(temp !=NULL){
				cout<<temp->data<<" -> ";
				temp = temp->right;
			}
			cout<<"NULL"<<endl;
		}
};

// static variable to track current index while building tree
static int idx=-1;

// Function to build binary tree using preorder traversal
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){
		return NULL;
	}
	
	// Create new node for current value
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}

int main(){
	vector<int>tree={1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
	
	// Build binary tree from vector representation
	Node* root=buildTree(tree);
	
	cout<<"\nRoot Element: "<<root->data<<endl;
	cout<<endl<<"-----------------------------------"<<endl;
	
	// Create Solution object
	Solution s;
	
	// Flatten the binary tree into linked list
	s.flatten(root);
	
	// Print the flattened linked list
	s.print();
	
    cout << endl;
    return 0;	
}