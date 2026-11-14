#include<iostream>
#include<vector>

using namespace std;

// Class to solve the Trapping Rain Water problem using two-pointer approach
class Solution{
	public:
		int tap(vector<int>&h){
			
			int n=h.size();
			int ans=0;
			
			int l=0;   // Left pointer
			int r=n-1;   // Right pointer
			
			int lmax =0;    // Maximum height to the left
			int rmax=0;   // Maximum height to the right
			
			while(l<r){   // Process until both pointers meet
			
				// Update left and right maximum heights
				lmax=max(lmax , h[l]);
				rmax=max(rmax , h[r]);
				
				// Compare left and right maximums
				if(lmax < rmax){
					ans+=lmax - h[l];    // Water trapped depends on left max (since right side is higher)
					l++;
				}else{
					ans+=rmax - h[r];      // Water trapped depends on right max (since left side is higher)
					r--;
				}
			}
			
			return ans;    // Return total trapped water
		}
};


int main(){
	Solution s;
	
	vector<int>h={4,2,0,3,2,5};   // Heights of bars
	
	int ans=s.tap(h);   // Function call to compute trapped rain water
	
	cout<<"Trapping rain water is -> "<<ans<<endl;
}






















