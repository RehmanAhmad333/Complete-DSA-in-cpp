#include<iostream>
#include<queue>

using namespace std;

//Stack Class (Implemented Using Two Queues)
class Stack{
	public:
		queue<int>q1;	// Main queue — always stores elements in correct stack order
		queue<int>q2;	// Helper queue — used during the push operation
		
		// Adds an element to the "top" of the stack
		void push_val(int val){
			
			while(!q1.empty()){   //Move all elements from q1 → q2
				q2.push(q1.front());
				q1.pop();
			}
			
			q1.push(val);   //Push the new element into q1 (it will become the top)
			
			while(!q2.empty()){    //Move all elements back from q2 → q1 (to maintain order)
				q1.push(q2.front());
				q2.pop();
			}
		}
		
		
		// Removes and returns the top element of the stack
		int pop_val(){
			if(q1.empty()){
				cout<<"Stack is UnderFlow.\n";
				return -1;
			}
			
			int val=q1.front();   // The front of q1 is the top of the stack
			q1.pop();
			
			return val;
		}
		
		// Returns the top element without removing it
		int top_Val(){
			if(q1.empty()){
				cout<<"Stack is UnderFlow.\n";
				return -1;
			}
			
			return q1.front();
		}
		
		// Checks if the stack is empty
		bool empty(){
			return q1.empty();
		}
		
		// Displays all elements in the stack from top → bottom
		void print() {
			if (q1.empty()) {
				cout << "Stack is empty.\n";
				return;
			}
	
			cout << "Stack elements (Top → Bottom): ";
			queue<int> temp = q1; 		// Make a copy to preserve original stack
			while (!temp.empty()) {
				cout << temp.front() << " ";
				temp.pop();
			}
			cout << endl;
		}
};

int main() {
	cout << "--- Stack Using Two Queues Demonstration ---\n\n";

	Stack s;

	// Push some elements
	s.push_val(10);
	s.push_val(20);
	s.push_val(30);
	s.push_val(40);

	cout << endl;
	s.print();

	// Check top element
	cout << "\n👆 Top element: " << s.top_Val() << endl;

	// Pop two elements
	s.pop_val();
	s.pop_val();
	cout << endl;
	s.print();
	
	s.push_val(50);   // Push new element
	cout << endl;
	s.print();

	cout << "\nIs stack empty? " << (s.empty() ? "Yes" : "No") << endl;    	// Check if empty
 
	while (!s.empty()) { 	// Pop all remaining elements
		s.pop_val();
	}
	cout << "\nAfter clearing all elements:\n";
	s.print();

	cout << "\n--- End of Demonstration ---\n";

	return 0;
}
