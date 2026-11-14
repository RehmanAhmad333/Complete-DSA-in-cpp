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

void inorder(Node* root , vector<int>&arr){
	if(root == NULL){
		return ;
	}
	
	inorder(root->left , arr);
	arr.push_back(root->data);
	inorder(root->right ,arr);
}

void sorted2Arrays(vector<int>arr1 , vector<int>arr2 , vector<int>&temp){
	int i =0 , j = 0;
	
	while(i < arr1.size() && j < arr2.size()){
		if(arr1[i] < arr2[j]){
			temp.push_back(arr1[i]);
			i++;
		}
		else{
			temp.push_back(arr2[j]);
			j++;
		}
	}
	
	while(i < arr1.size()){
		temp.push_back(arr1[i]);
		i++;
	}
	
	while(j < arr2.size()){
		temp.push_back(arr2[j]);
		j++;
	}
}

Node* buildBSTFromSorted(vector<int>arr , int st , int end){
	if(st > end){
		return NULL;
	}
	
	int mid = st+(end - st)/2;
	
	Node* root = new Node(arr[mid]);
	root->left = buildBSTFromSorted(arr , st , mid-1);
	root->right = buildBSTFromSorted(arr , mid + 1 , end);
	
	return root;
}

Node* Merge2BST(Node* root1 , Node* root2){
	vector<int>arr1 , arr2;
	inorder(root1 , arr1);
	inorder(root2 , arr2);
	
	vector<int>temp;
	
	sorted2Arrays(arr1 , arr2 , temp);
		
	return buildBSTFromSorted(temp , 0 , temp.size() - 1);
}

int main(){
	vector<int>tree1 = {8 ,2,1,10};
	vector<int>tree2 = {5,3,0};
	
	Node* root1 = buildBST(tree1);
	Node* root2 = buildBST(tree2);
	
	Node* root = Merge2BST(root1 , root2);
	
	vector<int>seq;
	inorder(root , seq);
	
	cout<<"Elements after merge two Binary Serch Tree : ";
	for(int val: seq){
		cout<<val<<"  ";
	}
	
	cout<<endl;
	return 0;
}