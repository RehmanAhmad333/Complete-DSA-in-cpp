#include<iostream>

using namespace std;

//Circular Queue Class
class CircularQueue{
	int* arr;        // Pointer to the dynamically allocated array
	int cap;         // Maximum capacity of the queue
	int currsize;    // Current number of elements in the queue
	int f, r;        // Front and rear indices
	
	public:
		//Constructor
		CircularQueue(int size){
			cap=size;
			
			arr=new int[cap];
			f = 0;          // Front starts at index 0
			r = -1;         // Rear starts before the array
			currsize = 0;   // Queue initially empty
		}
		
		// Adds (enqueues) a new element at the rear of the circular queue
		void push(int val){
			if(currsize >= cap){  // Queue full check
				cout<<"CQ is full.\n";
				return ;
			}
			r=(r + 1)%cap;  		// Move rear pointer in circular manner
			arr[r] = val;            // Insert new value
			currsize++;               // Increase size
			cout << "Inserted: " << val << endl;
			
		}
		
		// Removes (dequeues) an element from the front
		int pop(){
			if(is_empty()){
				cout<<"Array is empty.\n";
				return -1;
			}
			int value=arr[f]; 		// Store front element
			f = (f + 1) % cap;         // Move front forward circularly
			currsize--;                // Decrease size
			cout << "Removed: "<< value << endl;
			return value;
		}
		
		// Returns the element at the front without removing it
		int front(){
			if(is_empty()){
				cout<<"Array is empty.\n";
				return -1;
			}
			return arr[f];
		}
		
		// Checks if the queue is empty
		bool is_empty(){
			return currsize == 0;
		}
		
		// Displays all current elements in the queue (front ? rear)
		void print() const{
			if (currsize == 0) {
				cout << "??  Queue is empty.\n";
				return;
			}
					
			cout << "Circular Queue elements: ";
			for (int i = 0; i < currsize; i++) {
				int idx = (f + i) % cap;   		// Calculate index circularly
				cout << arr[idx] << " ";
			}
			cout << endl;
		}
		
		//Destructor 
		~CircularQueue() {
			delete[] arr;   // Free allocated memory
		}
};



int main() {
	CircularQueue cq(5);  // Create a circular queue of size 5
	// Enqueue some elements
	cq.push(10);
	cq.push(20);
	cq.push(30);
	cq.push(40);
	cq.push(50);
	cq.push(60);   // Should show "Queue is full"

	cout << endl;
	cq.print();    // Print all elements

	cout << "\nFront element: " << cq.front() << endl;

	// Dequeue two elements
	cq.pop();
	cq.pop();
	cout << endl;
	cq.print();

	// Add new elements to test circular property
	cq.push(70);
	cq.push(80);

	cout << endl;
	cq.print();

	cout << "\nFront element now: " << cq.front() << endl;
	return 0;
}
