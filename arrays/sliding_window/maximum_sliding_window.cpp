#include<iostream>
#include<vector>
#include<deque>

using namespace std;

// Class to find maximum in all subarrays (windows) of size k ,  using Deque (O(n) time)
class Solution{
	public:
		vector<int>maxSlidingWindow(vector<int>&a , int k){
			vector<int>ans;    // To store the maximums
			deque<int>dq;      // Will store indices (not actual values)
			
			//Process first window of size k --
			for(int i=0 ; i<k; i++){
				while(dq.size() > 0 && a[dq.back()] <=a[i]){  // Remove all elements smaller than current one from back
					dq.pop_back();
				}
				
				dq.push_back(i);   // Add current index at back
			}
			
			//Process remaining elements
			for(int i=k; i<a.size(); i++){
				ans.push_back(a[dq.front()]);  // Front of deque has the largest element for the previous window
				
				// Remove elements that are out of this window (left side)
				while(dq.size()>0 && dq.front() <= i-k){
					dq.pop_front();  
				}
				
				// Remove all smaller elements (since they’ll never be needed)
				while(dq.size()>0 && a[dq.back()] <= a[i]){
					dq.pop_back();
				}
				
				dq.push_back(i);   // Add current element's index
			}
			
			ans.push_back(a[dq.front()]);   // Add the max for the last window
			
			return ans;
		}
		
		// Utility function to print a vector
		void print(vector<int>&a) const{
			for(int i=0; i<a.size(); i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}


int main(){
	Solution s;
	
	// Example 1
	vector<int>v1={1,3,-1,-3,5,3,6,7};
	int k1=3;
	
	vector<int>ans1=s.maxSlidingWindow(v1, k1);
	
	cout<<"\nOriginal Array -> : ";
	s.print(v1);
	
	cout<<"\nMax of all subArray of size "<<k1<<" -> : ";
	s.print(ans1);
	
	// Example 2
	vector<int>v2={1,3,4,5,3,-1,-7,-3,0,5,9,3,-10,6,7};
	int k2=4;
	
	vector<int>ans2=s.maxSlidingWindow(v2,k2);
	
	cout<<"\nSecond Original Array -> : ";
	s.print(v2);
	
	cout<<"\nMax of all subArray of size "<<k2<<" -> : ";
	s.print(ans2);
	
	
}






