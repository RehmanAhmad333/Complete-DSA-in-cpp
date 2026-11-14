#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){  // Constructor to initialize node with data and set children to NULL
			data=val;
			left=right=NULL;
		}
};

static int idx=-1;    // static variable idx tree build karte waqt current index track karta hai

// Function to build binary tree using preorder traversal values
Node* buildTree(vector<int>tree){
	idx++;
	
	// Agar -1 milta hai to iska matlab yahaan NULL node hai (no child)
	if(tree[idx] == -1){
		return NULL;
	} 
	
	// Nai node create karo current value ke liye
	Node* root=new Node(tree[idx]);
	
	// Left aur Right subtree recursively build karo
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;  // Return the constructed node
}

// Function to find height of a binary tree
int height(Node* root){
	
	if(root == NULL){   // Base case: agar root null hai to height 0
		return 0;
	}
	
	// Left subtree aur Right subtree ki height nikal lo
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	
	return max(leftHeight ,rightHeight) + 1;	  // Tree ki height = 1 (for current node) + max of left and right height
} 

int main(){
	vector<int> tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node* root=buildTree(tree);    	// Tree build kar rahe hain
	
	cout<<"Root Element: "<<root->data<<endl;
	
	int treeHeight=height(root);    	// Height function call kar rahe hain
	
	cout<<"Height of tree : "<<treeHeight<<endl;	
}

