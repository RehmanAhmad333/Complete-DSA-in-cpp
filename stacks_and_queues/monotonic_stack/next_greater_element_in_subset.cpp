#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution{
	public:
		vector<int>nextGE(vector<int>&n1 , vector<int>&n2){  // Function to find Next Greater Element for elements of n1[] in n2[]
			unordered_map<int , int>m;  // map: stores element of n2 -> its Next Greater element
			vector<int>ans;   // result for elements in n1
			stack<int>s;    // stack to help find Next Greater Element (NGE)
			
			for(int i=n2.size()-1; i>=0; i--){   // Traverse n2[] from right to left
			
				while(s.size() >0 && n2[i] >= s.top()){   // Pop smaller or equal elements, they cannot be NGE for n2[i]
					s.pop();
				}
				if(s.empty()){   // If stack empty ? no greater element to right
					m[n2[i]] = -1;
				}else{   // Otherwise, top of stack is the Next Greater Element
					m[n2[i]] = s.top();
				}
				s.push(n2[i]);
			}
			// Build result for n1[] using the map we created from n2[]
			for(int i=0; i<n1.size(); i++){
				ans.push_back(m[n1[i]]);
			}
			
			return ans;
		}
		// Helper function to print results
		void print(vector<int>n , vector<int>ans){
			cout << "Next Greater Elements:\n";
            for(int i = 0; i < n.size(); i++) {
                cout << n[i] << " -> " << ans[i] << endl;
            }
		}
};
int main(){
    vector<int>n1 = {4, 1, 2};      // Query elements
    vector<int>n2 = {1, 3, 4, 2};   // Full array to build NGE map

    Solution s;

    // Compute Next Greater Elements for elements of n1[] in n2[]
    vector<int>ans = s.nextGE(n1, n2);

    // Print results
    s.print(n1, ans);

    return 0;
}




























