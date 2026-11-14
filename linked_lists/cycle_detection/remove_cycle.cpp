#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
};

class DLL{
	public:
		Node* deleteCircle(Node* head){
			Node* slow=head;
			Node* fast=head;
			
			bool iscycle=false;
			
			while(fast != NULL && fast->next != NULL){
				slow=slow->next;
				fast=fast->next->next;
				
				if (slow == fast){
					iscycle=true;
					break;
				}
			}
			
			if(!iscycle){
				cout<<"This list conn't contain any cycle.\n";
				return NULL;
			}
			
			slow=head;
			Node* pre=NULL;
			
			while(slow != fast){
				slow = slow->next;
				pre=fast;
				fast=fast->next;
			}
			
			pre->next=NULL;   //remove cycle
			return pre;  //return a address where the circle create
		}
};

int main(){
	
	// Creating a list: 3 -> 78 -> 4 -> 98 -> 0
    Node* head = new Node(3);
    head->next = new Node(78);
    head->next->next = new Node(4);
    head->next->next->next = new Node(98);
    head->next->next->next->next = new Node(60);

    // ? Create a cycle: last node (60) points back to node with value 4
    head->next->next->next->next = head->next->next;  

    DLL l;
    Node* cycle = l.deleteCircle(head);
	
	if (cycle != NULL){
		cout<<"Element that contain a cycle : "<<cycle->data<<endl;		
	}
	
	return 0;
}