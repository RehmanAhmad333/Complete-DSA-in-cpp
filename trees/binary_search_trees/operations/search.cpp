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
	if(root == NULL){ // if tree is empty, create new node
		return new Node(val);
	}
	
	if(val < root->data){  // if value smaller, go to left subtree
		root->left = insert(root->left , val);
	}
	else{ // if value greater or equal, go to right subtree
		root->right = insert(root->right , val);
	}
	
	return root;       // return updated root
}

// Function to build tree by inserting values one by one
Node* buildTree(vector<int>tree){
	Node* root=NULL;
	
	for(int val : tree){        // insert every element into BST
		root = insert(root , val);
	}
	
	return root;
}

// Function to search for a key in the BST
bool search(Node* root , int key){
	if(root == NULL){    // base case: if tree is empty
		return false;
	}
	if(root->data == key){  // key found at current node
		return true;
	}
	
	if(key < root->data){   // if key is smaller, search in left subtree
		return search(root->left , key);
	}else{    // else search in right subtree
		return search(root->right , key);
	}
}

// Function to print tree in inorder traversal (for verification)
void inorder(Node* root){
	if(root == NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" -> ";
	inorder(root->right);
}

int main(){
	vector<int>tree={3,2,1,5,6,4};
	
	// Build Binary Search Tree
	Node* root= buildTree(tree);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nCheck that our Tree Built in correct order (Inorder Traversal): \n\t\t\t\t\t\t\t";
	inorder(root);
	cout<<"NULL"<<endl;
	
	cout<<"\n--------------------------------------\n";
	
	// Now searching some keys in the BST
	int key1 = 5;
	int key2 = 7;
	int key3 = 2;
	
	cout<<"\nSearching key "<<key1<<" in BST : ";
	if(search(root , key1)){
		cout<<"Found ";
	}else{
		cout<<"Not Found ";
	}
	
	cout<<"\nSearching key "<<key2<<" in BST : ";
	if(search(root , key2)){
		cout<<"Found ";
	}else{
		cout<<"Not Found ";
	}
	
	cout<<"\nSearching key "<<key3<<" in BST : ";
	if(search(root , key3)){
		cout<<"Found ";
	}else{
		cout<<"Not Found ";
	}
	
	cout<<"\n\n--------------------------------------\n";

	
	cout<<endl;
	return 0;
}
