#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
	public:
		int largestRA(vector<int>&h){
			int n=h.size();
			vector<int>l(n,0);     // stores index of previous smaller element
            vector<int> r(n, 0);   // stores index of next smaller element

			
			stack<int>s;
			
			//Right Smaller , next Smaller
			for(int i= n-1; i >=0; i--){            // traverse from right to left
				while(s.size()>0 && h[i] <= h[s.top()]){
					s.pop();    // pop until we find a smaller element
				}
				r[i] = s.empty()? n:s.top();  // if none, boundary is n
				s.push(i);
			}
			
			while(!s.empty()){   // Clear stack for reuse
				s.pop();
			}
			
			//Left Smaller , prev smaller
			for(int i=0; i<n; i++){      // traverse from left to right
				while(s.size()>0 && h[i] <= h[s.top()]){
					s.pop();
				}
				
				l[i] = s.empty() ? -1 : s.top();      // if none, boundary is -1
				
				s.push(i);
			}
			
			
			int ans=0;
			for(int i=0; i<n; i++){
				int width=r[i] - l[i] -1; // width between smaller elements
				int currArea=h[i]*width;    // area = height × width
				
				ans=max(ans,currArea);     // keep track of max area
			}
			
			return ans;
		}
};

int main(){
	Solution s;
	
	vector<int>h={2,1,5,6,2,3};
	
	int area=s.largestRA(h);
	
	cout<<"Largest Rectangular Area in a Histogram is -> "<<area<<endl;
}


