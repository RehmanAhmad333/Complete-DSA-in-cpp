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
	
	if(tree[idx] == -1){   // -1 represents NULL (no child)
		return NULL;
	} 
	
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}

// Function to find the Lowest Common Ancestor (LCA) of two given nodes in a binary tree
Node* lowestCA(Node* root , int p, int q){
	if(root == NULL){
		return NULL;   // Base case: if root is NULL, return NULL
	}
	
	// If current node matches one of the target nodes, return it
	if(root->data == p || root->data == q ){
		return root;
	}
	
	// Recursively search in left and right subtrees
	Node* lLCA=lowestCA(root->left , p ,q);
	Node* rLCA=lowestCA(root->right , p ,q);
	
	// If both sides return non-NULL, current node is the LCA
	if(lLCA && rLCA){
		return root;
	}
	else if(lLCA != NULL){   	// If only one side returns non-NULL, propagate that upwards
		return lLCA;
	}else{
		return rLCA;
	}   
}

int main(){
 	vector<int> tree = {1,2,4,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root = buildTree(tree);
    cout << "Root Element: " << root->data << endl;

    // Find LCA of two nodes (4 and 9)
    Node* lca = lowestCA(root, 4, 9);
    if (lca)
        cout << "Lowest Common Ancestor of nodes 4 and 9 is: " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}















