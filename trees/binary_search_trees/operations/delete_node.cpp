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
	if(root == NULL){      // if tree is empty, create new node
		return new Node(val);
	}
	
	if(val < root->data){    // if value smaller, go to left subtree
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


// Function to find Inorder Successor (leftmost node in right subtree)
Node* getInorderSuccessor(Node* root){  
	while(root != NULL   &&   root->left != NULL){
		root = root->left;
	}
	
	return root;
}

// Function to delete a node from BST
Node* delNode(Node* root , int key){
	if(root == NULL){
		return NULL;
	}
	
	if(key < root->data){   // if key is smaller, go left
		root->left = delNode(root->left , key);
	}else if(key > root->data){   // if key is larger, go right
		root->right = delNode(root->right , key);
	}else{ // key == root
		// Handle cases where node has 0 or 1 child
		if(root->left == NULL){   // Case 1: No left child
			Node* temp = root->right;
			delete root;
			return temp;
		}else if(root->right == NULL){   // Case 2: No right child
			Node* temp= root->left;
			delete root ;
			return temp;
		}else{    // Case 3: Two children
			Node* IS=getInorderSuccessor(root->right);  // find inorder successor
			root->data = IS->data;                      // replace current node with IS value
			root->right = delNode(root->right , IS->data);  // delete IS node
		}
	}
	
	return root;
}

int main(){

	vector<int>tree={3,2,1,5,6,4};
	
	// Build Binary Search Tree
	Node* root= buildTree(tree);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nCheck that our Tree Build in correct order (Inorder Traversal): \n\t\t\t\t\t";
	inorder(root);
	cout<<endl;
	
	cout<<"\n--------------------------------------\n";
	
	// Now perform deletion operations
	cout<<"Deleting nodes from BST to understand how deletion works.\n\n";
	
	// Case 1: Delete leaf node (no children)
	cout<<"Deleting leaf node (1):\n";
	root = delNode(root , 1);
	cout<<"\tInorder after deleting 1 : ";
	inorder(root);
	cout<<"\n\n";
	
	// Case 2: Delete node with one child
	cout<<"Deleting node (6) which has one child:\n";
	root = delNode(root , 6);
	cout<<"\tInorder after deleting 6 : ";
	inorder(root);
	cout<<"\n\n";
	
	// Case 3: Delete node with two children
	cout<<"Deleting node (3) which has two children:\n";
	root = delNode(root , 3);
	cout<<"\tInorder after deleting 3 : ";
	inorder(root);
	cout<<"\n\n";
	
	cout<<"--------------------------------------\n";
	cout<<"All Deletion Operations Completed Successfully!\n";
	
	cout<<endl;
	return 0;
}
