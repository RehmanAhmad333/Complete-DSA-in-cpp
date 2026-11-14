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

Node* recoverBST(Node* root){
	Node* first=NULL;
	Node* sec =NULL;
	Node* prev = NULL;
		
	Node* curr = root;
	while(curr != NULL){
		if(curr->left == NULL){
			if(prev != NULL && curr->data < prev->data){
				if(!first)
					first = prev;
				sec = curr;
			}
			prev = curr;
			curr = curr->right;
		}
		else{
			Node* predecessor=curr->left;
			while(predecessor->right != NULL && predecessor->right != curr){
				predecessor = predecessor->right;
			}
			
			if(predecessor->right == NULL){
				predecessor->right = curr;
				curr = curr->left;
			}
			else{
				if(prev != NULL && curr->data < prev->data){
					if(!first)
						first = prev;
					sec = curr;
				}
				prev = curr;
				predecessor->right = NULL;
				curr = curr->right;
			}
		}
	}
		
	if (first && sec) {
	swap(first->data, sec->data);
	}
		
	return root;
}

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

	recoverBST(root);

    cout << "Inorder after fixing BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}