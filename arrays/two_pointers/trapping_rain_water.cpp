#include<iostream>
#include<vector>

using namespace std;

// Class containing solution for Trapping Rain Water problem
class Solution{
	public:
		
		// Function to calculate trapped rain water
		int tap(vector<int>&h){
			int n=h.size();  // Number of bars
        	int ans = 0;       // Total trapped water

        	// Arrays to store maximum heights on the left and right for each index	
			vector<int>lmax(n,0);
			vector<int>rmax(n,0);
			
			lmax[0]=h[0];     // First element's left max is itself
			rmax[n-1]=h[n-1];   // Last element's right max is itself
			
			for(int i=1; i<n; i++){   // Step 1: Fill lmax[] — maximum height to the left of each bar (including itself)
				lmax[i] = max(lmax[i-1], h[i]);
			}
			
			for(int i=n-2 ; i>=0; i--){    // Step 2: Fill rmax[] — maximum height to the right of each bar (including itself)
				rmax[i] = max(rmax[i+1], h[i]);
			}
			 
			cout<<"LMax:\n";    // Debug prints — show LMax 
			for(int i=0;i<n;i++){
				cout<<lmax[i]<<" ";
			}
			cout<<endl;
			
			cout<<"RMax:\n";    // Debug prints — show RMax 
			for(int i=0;i<n;i++){
				cout<<rmax[i]<<" ";
			}
			cout<<endl;
			
			
			// Water trapped at i = min(Lmax[i], Rmax[i]) - height[i]
			for(int i=0; i<n; i++){
				ans+=min(lmax[i] , rmax[i]) -h[i];
			}
			
			return ans;
		}
};

int main(){
	Solution s;
	
	vector<int>h={4,2,0,3,2,5};   // Heights of bars
	
	int ans=s.tap(h);   // Function call to compute trapped rain water
	
	cout<<"Trapping rain water is -> "<<ans<<endl;
}












