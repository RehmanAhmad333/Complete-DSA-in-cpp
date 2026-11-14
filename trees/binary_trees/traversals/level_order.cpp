#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Node class definition
class Node{
	public:
		int data;    // Value stored in the node
		Node* left;  // Pointer to left child
		Node* right;    // Pointer to right child
		
		Node(int val){
			data = val;
			left=right=NULL;
		}
};

static int idx=-1;    // Global index to track current element while building tree

// Function: buildTree
// Purpose : Builds a Binary Tree from a given preorder traversal
// Input   : Vector containing tree elements where -1 represents NULL
// Output  : Pointer to the root node
Node* bulitTree(vector<int>tree){
	idx++; // Move to the next element
	
	if(tree[idx]== -1){   // if current element is -1, it means NULL node
		return NULL;
	}
	
	Node* root=new Node(tree[idx]);   // Create a new node for the current value
	
	// Recursively build the left and right subtrees
	root->left=bulitTree(tree);
	root->right=bulitTree(tree);
	
	// Return the constructed node
	return root;
}


// Function: levelOrder
// Purpose : Prints the Binary Tree level by level (Breadth-First Search)
void levelOrder(Node* root){
	queue<Node*>q;  // Create a queue to store nodes for BFS traversal
	
	q.push(root);   //Push the root node first
	q.push(NULL);   //Push NULL as a marker to represent the end of a level
	
	//Traverse until queue is empty
	while(q.size() > 0){    
		Node* curr=q.front();    // Get the front node and remove it from the queue
		q.pop();
		
		// If we encounter NULL, it means the end of a level
		if(curr == NULL){
			if(!q.empty()){  // If there are still nodes left, print a new line for the next level
				cout<<endl;    // Push NULL again to mark the end of the next level
				q.push(NULL); 
				continue;
			}else{
				break;    // Queue empty -> all levels printed
			}
		}
		
		cout<<curr->data<<" ";   // Print current node's data
		
		
		// Enqueue left and right children (if they exist)
		if(curr->left !=NULL){
			q.push(curr->left);
		}
		if(curr->right != NULL){
			q.push(curr->right);
		}
	}
	cout<<endl;
}

int main(){
	vector<int>tree={1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
	
	// Build tree
	Node* root=bulitTree(tree);
		
	cout<<"Root -> "<<root->data<<endl;
	cout << "\nLevel Order Traversal:\n";
	
	// Perform level order traversal
	levelOrder(root);
	return 0;
}

























