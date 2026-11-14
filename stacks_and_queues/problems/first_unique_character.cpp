#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Class to find the first unique (non-repeating) character ,  in a given string using HashMap and Queue
class Solution{
	public:
		// Function to find index of first unique character
		int firstUniqueChar(string s){
			
			unordered_map<char , int>m; // Stores frequency of each character
			queue<int>q;    // Stores indices of characters that appear once (candidates)
			
			for(int i=0; i<s.size(); i++){
				if(m.find(s[i]) == m.end()){   // If character is seen first time, add its index to queue
					q.push(i);
				}
				
				m[s[i]] ++;    // Increase frequency of the character
				
				while(q.size() > 0 && m[s[q.front()]] >1){// Remove from queue if the front character is no longer unique
					q.pop();
				}
			}
			
			// If queue is not empty, front of queue is index of first unique char ,Else, return -1
			return q.size() > 0?q.front() : -1;
		}
};

int main(){
	Solution s;
	
	string str;
	cout<<"Enter String : ";
	getline(cin, str);  // Input a full line including spaces
	
	// Convert the string to lowercase (case-insensitive comparison)
	string lowerstr = str;
    transform(lowerstr.begin(), lowerstr.end(), lowerstr.begin(), ::tolower);
	
	int idx=s.firstUniqueChar(lowerstr);   // Get index of first unique character
	
	cout<<"\n\nOriginal String : "<<str<<endl;
	
	// If no unique character found
	if(idx == -1)
		cout<<"\nNo unique character found in the given string.\n";
	else
		cout<<"\nFirst Unique Character in your given string is -> '"<<str[idx]<<"'"<<endl;
	
	return 0;
}













