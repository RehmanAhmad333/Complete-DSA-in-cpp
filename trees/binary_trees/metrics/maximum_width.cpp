#include<iostream>
#include<vector>
#include<queue>

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
		// Function to find the maximum width of a binary tree
		int maxWidthofBT(Node* root){
			queue<pair<Node* ,unsigned long long>>q;  // Queue stores node and its index in tree level
			q.push({root , 0});         // Root node index is 0
			
			int maxWidth=0;
			
			while(q.size() > 0){
				int currLevelSize = q.size();  // Number of nodes at current level
				
				// Get start and end indices of the current level
				unsigned long long stIdx=q.front().second;
				unsigned long long endIdx=q.back().second;
				
				// Update maximum width (difference between end and start + 1)
				maxWidth = max(maxWidth ,int(endIdx - stIdx + 1));
				
				// Process all nodes of the current level
				for(int i = 0; i<currLevelSize ; i++){
					auto curr=q.front();
					q.pop();
					
					// For left child, index = 2*i + 1
					if(curr.first->left){
						q.push({curr.first->left , curr.second * 2 + 1});
					}
					
					// For right child, index = 2*i + 2
					if(curr.first->right){
						q.push({curr.first->right , curr.second * 2 + 2});
					}
				}
			}
			
			return maxWidth;  // Return the maximum width found
		}
};

int main(){
	Solution s;
	
	// Preorder representation of binary tree (-1 = NULL)
	vector<int>tree={1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
	
	Node* root=buildTree(tree);
	
	cout<<"Root Element: "<<root->data<<endl;
	
	// Calculate and print maximum width of binary tree
	
	int maxWidth=s.maxWidthofBT(root);
	
	cout<<"\nMaximum Width of binary Tree : "<<maxWidth<<endl;
	return 0;
}