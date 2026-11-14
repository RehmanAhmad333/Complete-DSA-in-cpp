#include<iostream>
#include<vector>

using namespace std;

// Node class represents a single node of the binary tree
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		// Constructor to initialize the node
		Node(int val){
			data=val;
			left=right=NULL;
		}
	
};

static int idx=-1;  // Static variable used to track current position in preorder array

// Function to build a binary tree from preorder representation
Node* buildTree(vector<int>tree){
	idx++;
	
	if(tree[idx] == -1){   // Base condition: if current value is -1, it means there’s no node (NULL)
		return NULL;
	} 
	
	// Create a new node for current index
	Node* root=new Node(tree[idx]);
	
	// Recursively build left and right subtrees
	root->left=buildTree(tree);
	root->right=buildTree(tree);
	
	return root;  // return root node of current subtree
}

// Function to check if two binary trees are exactly the same
bool isSameTree(Node* p , Node* q){

	if(p == NULL || q == NULL){   	// If either is NULL, both must be NULL to be considered same
		return p == q; 
	}
	
	// Recursively check left and right subtrees
	bool isLeftSame=isSameTree(p->left , q->left);
	bool isRightSame=isSameTree(p->right, q->right);
	
	// Trees are same only if:
	// 1. Left subtree is same
	// 2. Right subtree is same
	// 3. Current node data matches
	// This check all this conditions
	return isLeftSame && isRightSame && p->data == q->data ;
}

// Function to check whether one tree (subRoot) is a subtree of another (root)
bool isSubTree(Node* root , Node* subRoot){

	if(root == NULL || subRoot == NULL){    	// Base condition: if either tree is NULL
		return root == subRoot;
	}
	
	// If current nodes are equal and both trees match entirely
	if(root->data == subRoot->data && isSameTree(root , subRoot)){
		return true;
	}
	
	// Otherwise, recursively check in left or right subtree
	return isSubTree(root->left , subRoot) || isSubTree(root->right , subRoot);
}


int main() {

    vector<int> mainTree = {
        1,
            2,
                4, -1, -1,
                5,
                    8, -1, -1,
                    9, -1, -1,
            3,
                6, -1, -1,
                7, -1, -1
    };

    // SubTree that EXISTS inside mainTree
    vector<int> subTree_Exists = {
        5,
            8, -1, -1,
            9, -1, -1
    };

    //SubTree that does NOT exist in mainTree
    vector<int> subTree_NotExists = {
        2,
            4, -1, -1,
            10, -1, -1   // node 10 does not exist in main tree
    };
    // Build Main Tree
    idx = -1;
    Node* mainRoot = buildTree(mainTree);

    cout << "Root Element of Main Tree: " << mainRoot->data << endl;

    // ✅ Test 1: SubTree Exists
    idx = -1;
    Node* subRoot1 = buildTree(subTree_Exists);
    bool result1 = isSubTree(mainRoot, subRoot1);
    cout << "\nTest 1: Checking subtree_Exists...\n";
    if (result1) {
        cout << "SubTree of another Tree\n";
    } else {
        cout << "Not a SubTree of another Tree\n";
    }
    // ❌ Test 2: SubTree Does Not Exist
    idx = -1;
    Node* subRoot2 = buildTree(subTree_NotExists);
    bool result2 = isSubTree(mainRoot, subRoot2);
    cout << "\nTest 2: Checking subtree_NotExists...\n";
    if (result2) {
        cout << "SubTree of another Tree\n";
    } else {
        cout << "Not a SubTree of another Tree\n";
    }
    return 0;
}