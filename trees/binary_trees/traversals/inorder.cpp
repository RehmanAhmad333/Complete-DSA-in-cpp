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
			left=right=NULL;
		}
};

static int idx=-1;

Node* bulitTree(vector<int>tree){
	idx++;
	
	if(tree[idx]== -1){
		return NULL;
	}
	
	Node* root=new Node(tree[idx]);
	
	root->left=bulitTree(tree);
	root->right=bulitTree(tree);
	
	return root;
}

// Helper Function: printInOrder
// Purpose : To verify the tree structure by inorder traversal
void inorder(Node* root){
	if(root == NULL){
		return ;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	vector<int>tree={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	Node* root=bulitTree(tree);
		
	cout<<"Root -> "<<root->data<<endl;
	
	cout<<"\nInorder : Left , Root , Right.\n";
	inorder(root);
	
	return 0;
}














