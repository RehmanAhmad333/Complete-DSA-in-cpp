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
		Node* prev = NULL;
		int minDiffInBST(Node* root){
			if (root == NULL){
				return INT_MAX;
			}
			int ans = INT_MAX;
			
			if(root->left != NULL){
				int leftDiff=minDiffInBST(root->left);
				ans = min(ans , leftDiff);
			}
			
			if(prev != NULL){
				ans = min(ans , root->data - prev->data);
			}
			prev = root;
			
			if(root->right != NULL){
				int rightDiff = minDiffInBST(root->right);
				ans = min(ans , rightDiff);
			}
			
			return ans;
		}
};

int main(){
	vector<int>tree= {42, 52 ,62,82,83,88};
	Node* root = buildTree(tree);
	cout<<"Root of Tree : "<<root->data<<endl;
	
	Solution s;
	
	int minDiff = s.minDiffInBST(root);
	
	cout<<"Min distance between any two nodes : "<<minDiff<<endl;
	return 0;
}