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
		Node* prev= NULL;
		Node* first= NULL;
		Node* sec =NULL;
		
		void inorder(Node* root){
			if(root == NULL){
				return  ;
			}
			
			inorder(root->left);
			if(prev != NULL && prev->data > root->data){
				if(!first){
					first = prev;
				}
				sec = root;
			}
			prev = root;
			
			inorder(root->right);
		}
		
		Node* recoverBST(Node* root){
			Node* curr = root;
			inorder(curr);
			
			if(first != NULL && sec != NULL){
				int temp = first->data;
				first->data = sec->data;
				sec->data = temp;
			}
			
			return root;
		}
};

Node* insert(int val ,Node* root){
	if(root == NULL){
		return new Node(val);
	}
	if(val < root->data){
		root->left = insert(val , root->left);
	}
	else{
		root->right = insert(val ,root->right);
	}
	
	return root;
}

Node* buildBST(vector<int>&arr){
	Node* root=NULL;
	for(int val : arr){
		root = insert(val ,  root);
	}
	
	return root;
}

// Inorder print function
void printInorder(Node* root) {
    if (root == NULL) 
		return;
		
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main(){
	vector<int> tree = {6, 3, 1, 8, 4, 9};
    Node* root = buildBST(tree);

    // Manually swap two nodes to simulate error
    swap(root->data, root->left->right->data); // Swap 6 and 4 

    cout << "Inorder before fixing BST: ";
    printInorder(root);
    cout << endl;

    Solution obj;
    root = obj.recoverBST(root);

    cout << "Inorder after fixing BST: ";
    printInorder(root);
    cout << endl;

    return 0;
	
}