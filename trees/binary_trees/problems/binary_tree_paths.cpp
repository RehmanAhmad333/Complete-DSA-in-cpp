#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize a node with given value
		Node(int val){
			data=val;
			left=right=NULL;
		}		
};

class Solution{
	public:
		// Recursive function to find all paths from root to leaf
		void allpath(Node* root , vector<string>&ans , string path){
			
			// If current node is a leaf, store the complete path
			if(root->left == NULL && root->right == NULL){
				ans.push_back(path);
				return ;
			}
			
			// If left child exists, continue building path for left subtree
			if(root->left != NULL){
				allpath(root->left , ans, path+" -> "+to_string(root->left->data));
			}
			// If right child exists, continue building path for right subtree
			if(root->right != NULL){
				allpath(root->right , ans , path+" -> "+to_string(root->right->data));
			}
		}
		
		// Function to start from root and collect all binary tree paths
		vector<string>binaryTP(Node* root){
			vector<string>ans;
			string path = to_string(root->data);
			allpath(root , ans , path);
			return ans;
		}
};

// static variable to track current index while building tree
static int idx=-1;

// Function to build binary tree using preorder traversal
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){
		return NULL;
	}
	
	// Create new node for current value
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}




int main(){

	vector<int>tree={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	// Build binary tree
	Node* root=buildTree(tree);
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// Create Solution object to get all paths
	Solution s;
	vector<string>paths = s.binaryTP(root);
	
	// Display all root-to-leaf paths
	cout<<"All binary tree paths :\n";
	for(string p:paths){
		cout<<p<<endl;
	}
    
    cout << endl;
    return 0;	
}




