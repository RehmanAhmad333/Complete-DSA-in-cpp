#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node* next;
	
		Node(int val){
			data = val;
			left = right = next = NULL;
		}
};

class Solution{
	public:
		Node* connect(Node* root){
			if (root == NULL){
            	return NULL;
			}
			
			queue<Node*>q;
			q.push(root);
			q.push(NULL);
			
			Node* prev = NULL;
			while(q.size() > 0){
				Node* curr = q.front();
				q.pop();
				
				if(curr == NULL){
					prev = NULL; // reset for next level
					if(!q.empty()){
						q.push(NULL);
					}     
					else{
						break;
					}
				}
				else{
					if(prev != NULL){
						prev->next = curr;
					}
					if(curr->left != NULL){
						q.push(curr->left);
					}
					if(curr->right != NULL){
						q.push(curr->right);
					}
				}
				prev = curr; 
			}
			return root;
		}
};
void printUsingNext(Node* root) {
    Node* level = root;
    while (level != NULL) {
        Node* curr = level;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next; // move horizontally
        }
        cout << "? NULL" << endl; // end of level
        level = level->left; // move to next level (for perfect binary tree)
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    root = s.connect(root);

    cout << "Nodes connected at each level (using next pointer):" << endl;
    printUsingNext(root);

    return 0;
}