#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize node with given value
		Node(int val){
			data = val;
			left = right = NULL;
		}		
};

// Function to insert a node into the Binary Search Tree (BST)
Node* insert(Node* root , int val){
	if(root == NULL){           // if tree is empty, create new node
		return new Node(val);
	}
	
	if(val < root->data){       // if value smaller, go to left subtree
		root->left = insert(root->left , val);
	}
	else{        // if value greater or equal, go to right subtree
		root->right = insert(root->right , val);
	}
	
	return root;    // return updated root
}

// Function to build tree by inserting values one by one
Node* buildTree(vector<int>tree){
	Node* root=NULL;
	
	for(int val : tree){   // insert every element into BST
		root = insert(root , val);
	}
	
	return root;
}

// Function for inorder traversal (Left ? Root ? Right)
void inorder(Node* root){
	if(root == NULL){
		return ;
	}
	
	inorder(root->left);
	cout<<root->data << " , ";
	inorder(root->right);
	
}

int main(){
	// Elements to insert into the BST
	vector<int>tree={3,2,1,5,6,4};
	
	// Build Binary Search Tree
	Node* root= buildTree(tree);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nCheck that our Tree Build in correct order : \n\t\t\t\t\t";
	
	// Display inorder traversal (should be sorted for BST)
	inorder(root);
	cout<<endl;
	return 0;
}