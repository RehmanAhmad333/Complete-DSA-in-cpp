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
			data=val;
			left = right = NULL;
		}
};

// Helper function to build a balanced BST using sorted array
Node* helper(vector<int>tree  , int st, int end){
	if(st > end){                  // base case: no elements left to insert
		return NULL;
	}
	int mid= st + (end - st)/2;    // find the middle element to make balanced tree
	
	Node* root = new Node(tree[mid]);   // middle element becomes root
	
	// recursively build left and right subtrees
	root->left = helper(tree , st , mid-1);
	root->right = helper(tree ,mid+ 1 , end);
	
	return root;   // return constructed subtree
}

// Function to build tree using helper (driver function)
Node* buildTree(vector<int>tree){
	
	int st=0;
	int end= tree.size() - 1; 
	
	Node* root= helper(tree , st , end);
	
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
	// Sorted array to build Balanced BST
	vector<int>tree = {-10 ,-3 , 0 ,5, 9};
	
	cout<<"-------------------------------------------"<<endl;
	cout<<"Given Sorted Array : ";
	for(int val : tree){
		cout<<val<<"  ";
	}
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	// Build the Balanced BST
	Node* root = buildTree(tree);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	cout<<"\nInorder Traversal of BST (should print sorted order): \n\t\t\t\t\t";
	inorder(root);
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	return 0;
}
