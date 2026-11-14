#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	vector<int>arr={2,3,7,9,1,0,8};		// Input array
	vector<int>ans(arr.size() , 0);		// Output array to store the Previous Smaller Element (PSE) for each element
	stack<int>s;		// Stack to keep track of elements while finding previous smaller ones
	
	for(int i=0 ; i<arr.size(); i++){      // Traverse the array from left to right
		while(s.size() >0 && arr[i] <= s.top()){   // Remove (pop) all elements from stack that are >= current element
			s.pop(); 
		}
		if(s.empty()){   // If stack becomes empty, no smaller element exists on the left
			ans[i] = -1;
		}else{  	// Otherwise, top of stack is the previous smaller element
			ans[i] = s.top();
		}
		
		s.push(arr[i]);   // Push current element onto the stack
	}
	
	// Print the result
	cout<<"Previous Smaller Element : \n";
	for(int i=0 ; i<ans.size() ; i++){
		cout<<arr[i]<<" -> "<<ans[i]<<endl;
	}

	return 0;
}
















