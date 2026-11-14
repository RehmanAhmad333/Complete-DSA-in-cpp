#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;	
	Node(): data(0)	, next(nullptr){}
	Node(int x){
		data = x;
		next = nullptr;
	}
	Node(int x , Node* next){
		data= x;
		next=next;
	}
};

class RLL{
	public:
		Node* reverseList(Node* head){
			Node* pre=NULL;   //pointer to the previous node
			Node* curr=head;  //pointer to the current node that hold head
			Node* next=Null;  //pointer to the next node
			
			while(curr != NULL){   //run a while loop intil curr not equal to null
				next=curr->next;  //for every time run loop next is equal to current's next
				curr->next=pre;   //for every time run loop current's next is equal to previous
				
				//updates 
				pre=curr;      
				curr=next;
			}
			return pre;  //return a pre as a new header 
		}
};




int main(){
	
}