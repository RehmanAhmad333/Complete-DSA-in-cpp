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

//class for building tree using preorder and inorder traversals
class Solution{
	public:
		
		// Function to find index of a given value in inorder array
		int search(vector<int>inorder , int st , int end ,  int val){
			for(int i=st; i<=end; i++){
				if(inorder[i] == val){
					return i;
				}
			}
			return -1;
		}
		
		// Helper function to recursively build the tree
		Node* helper(vector<int>&preorder, vector<int>&inorder , int& preIdx , int left , int right){
			// Base case: when left index crosses right, subtree is empty
			if(left > right){
				return NULL;
			}
			
			Node* root=new Node(preorder[preIdx]);   // Create new node with current preorder element
			
			int inIdx=search(inorder , left , right , preorder[preIdx]); // Find the index of current root in inorder array
			
			preIdx++;     			// Move to next element in preorder
			
			// Recursively build left and right subtrees
			root->left=helper(preorder , inorder , preIdx , left , inIdx -1);
			root->right=helper(preorder , inorder , preIdx , inIdx + 1 , right);
			
			return root;
		}
		
		// Function to start tree building process
		Node* TreeBuild(vector<int>preorder, vector<int>inorder){
			int preIdx=0;
			
			return helper(preorder , inorder , preIdx , 0 , inorder.size()-1);
		}
		
		// Print tree in inorder
	    void printInorder(Node* root) {
	        if (root == NULL) 
				return;
				
	        printInorder(root->left);
	        cout << root->data << " -> ";
	        printInorder(root->right);
	    }
	
	    // Print tree in preorder
	    void printPreorder(Node* root) {
	        if (root == NULL)
				return;
				
	        cout << root->data << " -> ";
	        printPreorder(root->left);
	        printPreorder(root->right);
	    }
};



int main(){
	Solution s;
	
	// preorder and inorder traversal arrays
	vector<int>preorder={3,9,20,15,7};
	vector<int>inorder={9,3,15,20,7};
	
	// build tree using preorder and inorder
	Node* root=s.TreeBuild(preorder , inorder);
	
	cout<<"Pre Order Array : \n\t\t";
	for(int val : preorder){
		cout<<val<<" , ";
	}
	cout<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"\nIn Order Array : \n\t\t";
	for(int val : inorder){
		cout<<val<<" , ";
	}
	cout<<endl;
	cout<<"---------------------------------------------"<<endl;
	
	cout << "Inorder Traversal of Tree : \n\t\t";
    s.printInorder(root);
    cout << "\n---------------------------------------------\n";

    cout << "Preorder Traversal of Tree : \n\t\t";
    s.printPreorder(root);
    cout << endl;
    
    return 0;
}
