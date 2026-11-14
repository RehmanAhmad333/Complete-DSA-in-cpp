#include<iostream>
#include<vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data = val;
			left = right = NULL;
		}		
};
class Solution{
	public:	
		Node* helper(vector<int>& preOrder , int& i , int Ubound){
			if(i >= preOrder.size() || preOrder[i] > Ubound){
				return NULL;
			}
			
			Node* root = new Node(preOrder[i]);
			i++;
			
			root->left = helper(preOrder , i , root->data);
			root->right = helper(preOrder , i , Ubound);
			
			return root;
		}
		
		Node* buildTree(vector<int>& preOrder){
			int i =0;
			return helper(preOrder , i ,INT_MAX);
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
};

int main(){
	Solution s;
	
	vector<int>preOrder={6,3,1,4,8,9};
	
	// Build Binary Search Tree from PreOrder
	Node* root= s.buildTree(preOrder);
	
	cout<<"\nRoot Element : "<<root->data<<endl;
	
	cout<<"\n--------------------------------------\n";
	cout<<"\nCheck that our Tree Build in correct order : \n\t\t\t\t\t";
	
	// Display inorder traversal (should be sorted for BST)
	s.inorder(root);
	cout<<endl;
	return 0;
}