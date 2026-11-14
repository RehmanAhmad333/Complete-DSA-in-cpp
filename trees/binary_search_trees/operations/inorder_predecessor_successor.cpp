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

Node* rightMostInLeftSubtree(Node* root){
	Node* ans;
	while(root != NULL){
		ans = root;
		root= root->right;
	}
	return ans;
}

Node* leftMoseInRightSubtree(Node* root){
	Node* ans;
	while(root != NULL){
		ans = root;
		root= root->left;
	}
	return ans;
}

vector<int>getPredAndSucc(Node* root , int key){
	Node* curr = root;
	Node* pred = NULL;
	Node* succ = NULL;
	
	while(curr != NULL){
		if(key < curr->data){
			succ = curr;
			curr = curr->left;
		}
		else if(key > curr->data){
			pred = curr;
			curr = curr->right;
		}
		else{  //key == root
			if(curr->left != NULL){
				pred = rightMostInLeftSubtree(curr->left);
			}
			
			if(curr->right != NULL){
				succ = leftMoseInRightSubtree(curr->right);
			}
			break;
		}
	}
	
	int predVal = (pred != NULL) ? pred->data : -1;
    int succVal = (succ != NULL) ? succ->data : -1;

    return {predVal, succVal};
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPredAndSucc(root, key);

    cout << "Key: " << key << endl;
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}