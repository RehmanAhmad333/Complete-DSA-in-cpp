#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize a new node with given data
		Node(int val){
			data=val;
			left=right=NULL;
		}
	
};
static int idx=-1;

// Function to build a binary tree from a vector using preorder traversal
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){  	// Base case: if current element is -1, return NULL
		return NULL;
	} 
	
	Node* root=new Node(tree[idx]);   	// Create a new node with current value
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}

// Function to print all nodes present at the Kth level of the binary tree
void kthLevel(Node* root, int k){
	if(root == NULL){
		return ;   // Base case: if node is NULL, return
	}
	
	if(k==1){
		cout<<root->data<<" ";   	// If k becomes 1, we have reached the required level
		return;
	}
	
	// Recursively call for left and right subtrees, reducing k by 1 each time
	kthLevel(root->left , k-1);
	kthLevel(root->right , k-1);
}
int main(){
	vector<int> tree = {1, 2,-1,-1,3,4,-1,-1,5,-1,-1};
	int k=3;   // ? specify which level you want to print (e.g., 3rd level)
	
	Node* root=buildTree(tree);
	cout<<"Root Element: "<<root->data<<endl;

	kthLevel(root , k);   	// Print all nodes at the Kth level
	return 0;		
}