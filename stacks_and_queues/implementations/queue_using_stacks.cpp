#include<iostream>
#include<stack>

using  namespace std;

//Queue Class (Implemented Using Two Stacks)
class Queue{
	public:
		stack<int>s1;   // Main stack to hold elements in queue order
		stack<int>s2;	// Helper stack used during enqueue (push)
		
		// Enqueue operation — inserts an element at the end of the queue
		void push(int val){
			
			while(!s1.empty()){    //Move all elements from s1 → s2
				s2.push(s1.top());
				s1.pop();
			}
			
			s1.push(val);   //Push the new element into s1
			
			while(!s2.empty()){    //Move all elements back from s2 → s1
				s1.push(s2.top());
				s2.pop();
			}
		}
		
		
		// Dequeue operation — removes the element at the front of the queue
		int pop(){
			if(s1.empty()){
				cout<<"Stack is UnderFlow.\n";
				return -1;
			}
			int ans=s1.top();      // The top of s1 is the front of the queue
			s1.pop();
			return ans;
		}
		
		// Returns the element at the front of the queue without removing it
		int front(){
			if(s1.empty()){
				cout<<"Queue is UnderFlow.\n";
				return -1;
			}
			return s1.top();
		}
		
		// Checks whether the queue is empty
		bool is_empty(){
			return s1.empty();
		}
		
		
		// Prints all elements of the queue (Front → Rear)
		void print() const{
			
			if(s1.empty()){
				cout<<"Queue is empty.\n";
				return ;
			}
			
			stack<int>temp =s1;   // Make a copy to preserve original Queue
			cout<<"Queue Elements : ";
			while(!temp.empty()){
				cout<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
};

int main() {
    cout << "	  Queue Using Two Stacks Demonstration 	\n\n";

    Queue q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << endl;
    q.print();
    
    cout << "\nFront element: "<< q.front() << endl;  // Display front element

    q.pop();        // Dequeue two elements
    q.pop();

    cout << endl;
    q.print();

    q.push(50);       // Enqueue more elements
    q.push(60);

    cout << endl;
    q.print();

    cout << "\nFront element now: " << q.front() << endl;     // Display front again

    cout << "\nClearing the queue...\n";     // Empty the queue completely
    while (!q.is_empty()) {
        q.pop();
    }
    cout << endl;
    q.print();
    cout << "\n    End of Demonstration    \n";
    return 0;
}



