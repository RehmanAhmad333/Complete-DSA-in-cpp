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

// Helper function to validate if tree follows BST rules
bool helper(Node* root , Node* min , Node* max){
	if(root == NULL){
		return true;   // return true if all nodes are checked and valid
	}
	
	if(min != NULL && root->data <= min->data){
		return false;   // invalid: node value is less or equal to left limit
	}
	if(max != NULL && root->data >= max->data){
		return false;   // invalid: node value is greater or equal to right limit
	}
	
	// Check recursively for both left and right subtrees
	return helper(root->left , min  , root ) && helper(root->right , root , max);
}

// Main function that calls helper and returns final result
bool isValid(Node* root){
	return helper(root , NULL , NULL);
}

// Function for inorder traversal to verify tree visually
void inorder(Node* root){
	if(root == NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<"  ";
	inorder(root->right);
}


int main(){
	vector<int>tree={3,2,1,5,6,4};
	
	// Build Binary Search Tree
	Node* root= buildTree(tree);
	
	cout<<"\n--------------------------------------\n";
	cout<<"Root Element : "<<root->data<<endl;
	cout<<"--------------------------------------\n";
	
	cout<<"\nInorder Traversal of the Tree (should be sorted if valid BST):\n\t";
	inorder(root);
	cout<<endl;
	
	cout<<"\n--------------------------------------\n";
	cout<<"Now checking whether the given tree is a valid BST or not...\n";
	
	if(isValid(root)){
		cout<<"\nThe Tree is a Valid Binary Search Tree (BST)!\n";
	}else{
		cout<<"\nThe Tree is NOT a Valid Binary Search Tree (BST)!\n";
	}
	
	cout<<"\n--------------------------------------\n";
	
	// Example test: making tree invalid manually
	cout<<"\nNow making tree invalid manually (breaking BST property)...\n";
	root->left->right = new Node(10);   // invalid, because 10 > 3 but in left subtree
	
	cout<<"Checking again after modification...\n";
	if(isValid(root)){
		cout<<"\nThe Tree is a Valid Binary Search Tree (BST)!\n";
	}else{
		cout<<"\nThe Tree is NOT a Valid Binary Search Tree (BST)!\n";
	}
	
	cout<<"\n--------------------------------------\n";
	
	return 0;
}











