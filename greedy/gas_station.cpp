#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public:
		int gasCompletecircuit(vector<int>&gas , vector<int>&cost){
			
			int totalGas = 0;   // Total gas available in all stations
			int totalCost = 0;  // Total gas required for the entire trip
			
			int currGas = 0;    // Current gas balance while traversing
			int start = 0;      // Starting station index

			// Traverse through all stations
			for(int i=0; i<gas.size(); i++){
				
				totalGas +=gas[i];
				totalCost +=cost[i];
				
				currGas+=gas[i]-cost[i];  // gain or loss from this station
				
				if(currGas < 0){   // If at any point we can't move to next station, reset start to next station and reset current gas.
					start = i+1;
					currGas=0;
				}
			}
			
			// If total gas >= total cost, we can complete the circuit , Otherwise, it’s impossible (return -1)
			return totalGas >= totalCost ? start : -1;
		}
};


int main(){
	Solution s;

	// Example 1
	vector<int> gas1 = {1, 2, 4, 5, 9};
	vector<int> cost1 = {3, 4, 1, 10, 1};

	int ans1 = s.gasCompletecircuit(gas1, cost1);

	cout << "\nExample 1:\nGas Stations: ";
	for(int g : gas1) cout << g << " ";
	cout << "\nCosts: ";
	for(int c : cost1) cout << c << " ";

	if(ans1 != -1)
		cout << "\nYou can start from station index: " << ans1  << endl;
	else
		cout << "\nIt is impossible to complete the circuit." << endl;


	// Example 2 
	vector<int> gas2 = {2, 3, 4};
	vector<int> cost2 = {3, 4, 3};

	int ans2 = s.gasCompletecircuit(gas2, cost2);

	cout << "\nExample 2:\nGas Stations: ";
	for(int g : gas2) cout << g << " ";
	cout << "\nCosts: ";
	for(int c : cost2) cout << c << " ";

	if(ans2 != -1)
		cout << "\nYou can start from station index: " << ans2 << endl;
	else
		cout << "\nIt is impossible to complete the circuit." << endl;

	return 0;
}