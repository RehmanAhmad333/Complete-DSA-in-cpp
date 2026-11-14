#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	vector<int>arr = {6,8,0,1,3};  // Input array
	vector<int>ans(arr.size() , 0);   // Output array to store next greater element for each index - Initialized with 0
	stack<int>s;    // Stack to keep potential "next greater elements"
	
	for(int i=arr.size()-1 ; i>=0; i--){   // Traverse the array from right to left
	
		// Pop all smaller or equal elements from stack because they cannot be "next greater" for arr[i]
		while(s.size()>0 && arr[i] >= s.top()){
			s.pop();
		}
		if(s.empty()){	// If stack is empty, it means there is no greater element to the right
			ans[i] = -1;
		}else{	// Otherwise, the top element of stack is the next greater
			ans[i] = s.top();
		}
		
		s.push(arr[i]);	   // Push the current element into stack (may serve as NGE for elements on the left)	
	}
	
	// Print the result
	for(int val:ans){
		cout<<val<<" ";
	}
	cout<<endl;
	return 0;
}



