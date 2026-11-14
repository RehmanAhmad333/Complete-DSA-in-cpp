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
			left=right=NULL;
		}			
};

static int idx=-1;

// Function to build a binary tree using preorder traversal 
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){   // -1 represents NULL node (no child)
		return NULL;
	}
	
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}


class Solution{
	public:
		// Function to perform Inorder Traversal using Morris Traversal method
		// This method does not use recursion or stack (O(1) space)
		vector<int>InorderTraversal(Node* root){
			vector<int>ans;
			Node* curr=root;
			
			while(curr != NULL){
				if(curr->left == NULL){
					ans.push_back(curr->data);    // If there is no left child, visit current node and move right
					curr = curr->right;
				}else{
					// Find Inorder Predecessor (rightmost node of left subtree)
					Node* IP=curr->left;
					while(IP->right != NULL && IP->right != curr){
						IP=IP->right;
					}
					
					if(IP->right == NULL){
						IP->right=curr;     // Create temporary link to current node
						curr = curr->left;
					}else{
						IP->right=NULL;   // Remove temporary link and visit current node
						ans.push_back(curr->data);
						curr= curr->right;
					}
				}
			}
			
			return ans;  // Return the inorder traversal result
		}
};

int main(){
	Solution s;
	
	// Preorder representation of binary tree (-1 = NULL)
	vector<int>tree={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	
	Node* root=buildTree(tree);
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// Perform inorder traversal using Morris Traversal
	vector<int>InOrderTree=s.InorderTraversal(root);
	
	cout<<"\nInorder Traversal using Morris Method :- \n\t\t\t\t\t";
	for(int val : InOrderTree){
		cout<<val<< "  ";
	}
	
	cout<<endl;
	return 0;
}