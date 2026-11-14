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

Node* insert(Node* root , int val){
	if(root == NULL){
		return new Node(val);
	}
	if(val < root->data){
		root->left = insert(root->left , val);
	}
	else{
		root->right = insert(root->right , val);
	}
	
	return root;
}

Node* buildTree(vector<int>tree){
	Node* root=NULL;
	for(int val: tree){
		root = insert(root , val);
	}
	return root;
}

class Solution{
	public:
		int preOrder = 0;
		int kthSmaller(Node* root, int k){
			if (root == NULL){
				return -1 ;
			}
			
			if(root->left != NULL){
				int leftAns = kthSmaller(root->left , k);
				if(leftAns != -1){
					return leftAns;
				}
			}
			if(preOrder + 1 == k){
				return root->data;
			}
			preOrder +=1;
						
			if(root->right != NULL){
				int rightAns = kthSmaller(root->right , k);
				if(rightAns != -1){
					return rightAns;
				}
			}
			return -1;
		}
};

int main(){
	vector<int>tree= {1,2,3,4,5,6};
	Node* root = buildTree(tree);
	cout<<"Root of Tree : "<<root->data<<endl;
	
	Solution s;
	int k=3;
	int smallerVal = s.kthSmaller(root , k);
	
	cout<<"Kth Smaller node in Binary Search Tree : "<<smallerVal<<endl;
	return 0;
}