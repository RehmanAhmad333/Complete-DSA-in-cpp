#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data=val;
			left=right=NULL;
		}
	
};

static int idx=-1;

// Function to build a binary tree using preorder traversal
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){   // -1 represents a NULL (no child)
		return NULL;
	} 
	
	Node* root=new Node(tree[idx]);
	

	root->left=buildTree(tree);  	// Recursively build the left subtree
	root->right=buildTree(tree);    	// Recursively build the right subtree
	
	return root;
}

int ans=0;

// Function to calculate height of the tree  , while also updating the diameter (stored in ans)
int height(Node* root){
	if(root == NULL){
		return 0;
	}
	
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	
	ans=max(ans, leftHeight + rightHeight);   	// Update maximum diameter found so far
	
	return max(leftHeight ,rightHeight) + 1;   	// Return height of current node
	
}

// Function to find the diameter of the tree
int diameter(Node* root){
	if(root == NULL){
		return 0;
	}
	
	// Calculate height (which also updates ans)
	height(root);
	return ans;
}

int main(){
	vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node* root=buildTree(tree);  	// Build the tree from vector
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// Print the diameter of the tree
	cout<<"Diameter is  : "<<diameter(root)<<endl;
	
}




















