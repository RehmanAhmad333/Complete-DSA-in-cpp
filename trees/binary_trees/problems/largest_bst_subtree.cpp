#include<iostream>
#include<vector>
#include <climits>

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

class Info{
	public:
		int min , max , sz;
		
		Info(int mi , int mx , int size){
			min = mi;
			max = mx;
			sz = size;
		}
};

Info helper(Node* root){
	// Base case: Empty tree
	if(root == NULL){
		return Info(INT_MAX , INT_MIN , 0);  //return that last node has (+inf , -inf , size 0)
	}
	
	Info left = helper(root->left);
	Info right = helper(root->right);
	// Check if current subtree is a BST
	if(root->data > left.max && root->data < right.min){
		int currMin= min(root->data , left.min);
		int currMax = max(root->data , right.max);
		int currSz = left.sz + right.sz + 1;
		
		return Info(currMin , currMax , currSz);
	}
	
	// If not BST, return size of largest BST so far
	return Info(INT_MIN , INT_MAX , max(left.sz , right.sz));
}

int LargestBSTinBT(Node* root){
	Info info=helper(root);
	return info.sz;
}

int main(){
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(15);
	root->left->left = new Node(1);
	root->left->right = new Node(8);
	root->right->right = new Node(7);
	
	int size = LargestBSTinBT(root);
	
	cout<<"Largest BST in Binary Tree : "<<size<<endl;
	
	return 0;	
}