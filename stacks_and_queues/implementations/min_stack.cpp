#include<iostream>
#include<stack>

using namespace std;

// A custom stack class that supports:
// 1. Normal push and pop
// 2. Get the minimum element in O(1) time
class MinStack{
	public:
		stack<long long int>s;   // Stack to store encoded/normal values
        long long int minVal;    // Current minimum value in the stack
        
		// Push operation
		void push(int val){
			if(s.empty()){   // First element, directly push and set minVal
				s.push(val);
				minVal = val;
			}else{
				if(val < minVal){     
					s.push((long long)2*val - minVal);   // Encode value before pushing to maintain min tracking , Encoded = 2*val - minVal
					minVal=val;  // Update new minimum
				}else{
					s.push(val);    // Normal push
				}
			}
		}		
		//Pop Operation
		void pop(){
			if(s.top() < minVal){    // If top < minVal, it means the top is encoded
				minVal=2*minVal - s.top();    // Restore previous minimum using decoding formula
			}
			s.pop();
		}
		
		// Top Operation
		int top(){
			if(s.top() < minVal){   // If top < minVal → it’s an encoded value, so return minVal
				return minVal;
			}
			return s.top();
		}
		// Get current min Value
		int getMinVal(){
			return minVal;
		}
};

int main(){
	MinStack s;
	
	// Push values
    s.push(20);
    s.push(-20);
    s.push(1);
    s.push(-12);
    s.push(10);

    // Pop last two values (10 and -12)
    s.pop();
    s.pop();

    // Display top and min value
    cout<<"Top Value : "<<s.top()<<endl;
    cout<<"Min Val : "<<s.getMinVal()<<endl;

    return 0;
}