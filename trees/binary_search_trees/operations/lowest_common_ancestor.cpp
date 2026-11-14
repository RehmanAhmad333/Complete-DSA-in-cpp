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

class Solution{
	public:
		Node* LCA(Node* root , int p , int q){
			if(root == NULL){
				return NULL;
			}
			if(root->data > p && root->data > q){ //search in left subtree
				return LCA(root->left , p , q);
			}
			else if(root->data < p && root->data < q){  //search in right subtree
				return LCA(root->right , p ,q);
			}
			else{
				return root;
			}
		}
};

int main(){
	// Elements to insert into the BST
	vector<int>tree={6,2,0,4,3,5,8,7,9};
	
	// Build Binary Search Tree
	Node* root= buildTree(tree);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	
	Solution s;
	
	//Example 1
	int p = 7;
	int q = 9;
	
	Node* LCAroot1 = s.LCA(root , p , q);
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nLowest Common Ancestor of "<<p<<" and "<<q<<"  : "<<LCAroot1->data<<endl;

	//Example 2
	p = 0;
	q = 5;
	
	Node* LCAroot2 = s.LCA(root , p , q);
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nLowest Common Ancestor of "<<p<<" and "<<q<<"  : "<<LCAroot2->data<<endl;
	
	return 0;
}