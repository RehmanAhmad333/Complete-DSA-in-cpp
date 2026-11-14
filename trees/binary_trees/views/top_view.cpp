#include<iostream>
#include<vector>
#include<queue>
#include<map>

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
	
	if(tree[idx] == -1){   // -1 represents NULL node (no child)
		return NULL;
	} 
	
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;
}

// Function to print the Top View of a binary tree
void topView(Node* root){
	if(root == NULL){
		return;
	}
	
	queue<pair<Node* , int>>q;   // queue stores pair of (node, horizontal distance)
	map<int,int>m;               // map stores first node for each horizontal distance
	
	q.push({root , 0});          // root node has horizontal distance 0
	
	while(!q.empty()){
		Node* curr=q.front().first;
		int currHD=q.front().second;
		
		q.pop();
		
		// If horizontal distance is not present in map, store the node data
		if(m.find(currHD) == m.end()){
			m[currHD] = curr->data;
		}
		
		// For left child, horizontal distance decreases by 1
		if(curr->left != NULL){
			q.push({curr->left , currHD - 1});
		}
		// For right child, horizontal distance increases by 1
		if(curr->right != NULL){
			q.push({curr->right , currHD + 1});
		}
		
	}
	
	// Print all nodes stored in map (sorted by horizontal distance)
	for(auto it: m){
		cout<<it.second<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> tree = {1, 2,-1,-1,3,4,-1,-1,5,-1,-1};

	// Build binary tree from vector
	Node* root=buildTree(tree);
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// Print Top View of binary tree
	topView(root);
	
	return 0;	
	
}


