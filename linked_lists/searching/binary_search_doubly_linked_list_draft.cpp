#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* pre;

        // Constructor to initialize node with value
        Node(int val) {
            data = val;
            next = pre = NULL;
        }
};

class DLL {
    public:
        Node* head; // pointer to first node
        Node* tail; // pointer to last node

        // Constructor: initializes empty list
        DLL() {
            head = tail = NULL;
        }

        // Insert a new node at the front
        void push_front(int val) {
            Node* newNode = new Node(val);
            if (head == NULL) {  // if list is empty
                head = tail = newNode;
                return;
            } else {
                newNode->next = head; // connect new node to current head
                head->pre = newNode;  // link back from old head
                head = newNode;       // update head
                return;
            }
        }

        // Insert a new node at the back
        void push_back(int val) {
            Node* newNode = new Node(val);
            if (head == NULL) {  // if list is empty
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode; // connect current tail to new node
                newNode->pre = tail;  // link back from new node
                tail = newNode;       // update tail
                return;
            }
        }

        // Remove node from the front
        void pop_front() {
            if (head == NULL) {
                cout << "The linked list is empty.\n";
                return;
            } else {
                Node* temp = head;     // store current head
                head = temp->next;     // move head forward
                if (head != NULL) {    // if list not empty after removal
                    head->pre = NULL;  // remove backward link
                }
                temp->next = NULL;     // disconnect old node
                delete temp;           // free memory
                return;
            }
        }

        // Remove node from the back
        void pop_back() {
            if (head == NULL) {
                cout << "The linked list is empty.\n";
                return;
            } else {
                Node* temp = tail;     // store current tail
                tail = temp->pre;      // move tail backward
                if (tail != NULL) {    // if list not empty after removal
                    tail->next = NULL; // remove forward link
                }
                temp->pre = NULL;      // disconnect old node
                delete temp;           // free memory
                return;
            }
        }

        // Print the entire list
        void print() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            return;
        }
        
        Node* helper(Node* head , Node* tail , int tag){
        	if(head->data > tail->data){
        		return NULL;
			}
			
			Node* slow = head;
			Node* fast= head;
			
			while (fast != NULL && fast->next != tail){
				slow = slow->next;
				fast = fast->next->next;
			}
			print(slow->data);
			
//			if(tag < slow->data){
//				helper(head , slow->pre);
//			}
//			else if(tag > slow->data){
//				helper(slow->next , tail);
//			}
//			else{
//				return slow->data;
//			}
//		}
		
		Node* binSearch(int tag){
			return helper(head , tail , tag);
		}
};


// Main function 
int main() {
    DLL l;

    // Insert elements at both ends
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);


    // Print final list
    l.print();
    cout << "End program\n";
    return 0;
    
    int tag = 5;
    
    Node* findval = l.binSearch(tag);
    
    if(findval){
    	cout<<tag<<" is found\n";
	}else{
		cout<<tag<<" is not found\n";
	}
	
	return 0;
	
}































