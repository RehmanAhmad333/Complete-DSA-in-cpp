	#include<iostream>
	
	using namespace std;
	
	// 				 Node Class 
	// Represents a single node in the linked list.
	// Each node stores an integer value (data) and a pointer to the next node.
	class Node{
		public:
			int data;
			Node* next;
			
			Node(int val){   // Constructor to initialize node with value and null next pointer
				data=val;
				next=NULL;
			}	
	};
	
	
	// 				 Queue Class 	 
	// Implements a Queue using a Linked List (FIFO: First In, First Out)
	class Queue{
		public:
			Node* head;		// Points to the front of the queue
			Node* tail;		// Points to the rear (end) of the queue
			
			Queue(){  // Constructor initializes empty queue
				head=tail=NULL;
			}
			
			// Adds (enqueues) an element at the end of the queue
			void push(int val){
				Node* newNode=new Node(val);   // Create new node
				
				if(head==NULL){    // If queue is empty, both head and tail will point to new node
					head=tail=newNode;
					
					return ; 	// Important: return here to avoid duplicate linking
				}
				
				tail->next=newNode;
				tail=newNode;
			}
			
			// Removes (dequeues) an element from the front of the queue
			int pop(){
				
				if(is_empty()){			// If queue is empty, cannot remove
					cout<<"LL is empty\n";
					return -1;
				}else{
					int value=head->data;    // Store data of front node
					
					Node* temp=head;	// Save current head node	
					head=head->next;	// Move head to next node
					
					temp->next=NULL; 	// Disconnect old head
					delete temp;		// Free memory
					
					// If after deletion queue becomes empty, reset tail
					if (head == NULL)
						tail = NULL;
					
					return value;
				}
				
			}
			
			// Returns the value at the front of the queue without removing it
			int front(){
				if(is_empty()){
					cout<<"LL is empty\n";
					return -1;
				}else{
					return head->data;
				}
			}
			
			// Checks whether the queue is empty or not
			bool is_empty(){
				return head==NULL;
			}
			
			// Displays all elements in the queue from front to rear
			void print() const{
				Node* temp=head;
				
				cout<<"Queue elements :  ";
				while(temp!=NULL){
					cout<<temp->data<<"  ";
					temp=temp->next;
				}
				cout<<endl;
			}
	};
	
	int main(){
		Queue q;   // Create queue object
		
		q.push(12);   // Enqueue 12
		q.push(20);   // Enqueue 20
		q.push(30);   // Enqueue 30
		
		q.pop();      // Dequeue (removes 12)
		
		cout<<"Front value: "<<q.front()<<endl;  // Shows 20
		
		q.push(40);   // Enqueue 40
		q.push(50);   // Enqueue 50
		
		q.print();    // Display queue: 20 30 40 50
		
		return 0;
	}
