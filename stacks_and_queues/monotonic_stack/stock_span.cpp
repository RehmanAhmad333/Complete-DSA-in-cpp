#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){	
	vector<int>p = {100,80,60,70,60,75,85};   // Input prices of stocks for each day
	vector<int>ans(p.size() , 0);    // Result vector to store span for each day (initialized with 0)
	stack<int>s;   // Stack to store indices of days
	
	for(int i=0; i<p.size() ; i++){   // Loop through all days
		// Pop elements from stack while current price >= price at stack top , (i.e., remove all previous days with lower or equal prices)
		while(s.size() > 0 && p[i] >= p[s.top()]){
			s.pop();
		}	
		// If stack is empty, it means all previous prices were smaller,
		// so span = i+1 (all days including current)
		if(s.empty()){   
			ans[i] = i+1;
		}else{   // Otherwise, span = distance between current day and last higher price
			ans[i] = i-s.top();   // i - prevHigh
		}
		s.push(i);	// Push current day index onto stack	
	}
	for(int i=0; i<ans.size(); i++){    // Print the span for each day
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}


