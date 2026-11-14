#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//  			 Node Class 
// Each Node stores a (key, value) pair and links to the previous and next nodes
// It helps build a Doubly Linked List structure
class Node{
	public:
		int key , val;
		Node* next;
		Node* prev;
		
		Node(int k , int v){
			key =k;
			val=v;
			next=prev=NULL;
		}
};


//                 LRUCache Class 
// Inherits from Node (though inheritance isn’t needed here)
// Implements Least Recently Used (LRU) Cache
// Uses a combination of:
//   1. Doubly Linked List → to track usage order (most recent at head)
//   2. Hash Map → to access nodes in O(1) time

class LRUCache{
	public:
		Node* head=new Node(-1,-1);    // Dummy head (front)
		Node* tail=new Node(-1,-1);    // Dummy tail (back)
		
		int limit;    // Maximum capacity of cache
		unordered_map<int , Node*>m;   // Key → Node* mapping for O(1) lookup

		
		// Constructor: sets cache capacity and links head/tail
        LRUCache(int cap) {
            limit = cap;
            
            head->next = tail;
            tail->prev = head;
        }
		
		
		// Adds a new node right after the head (most recently used position)
		void addNode(Node* newNode){     
			Node* oldNode=head->next;  // Store the node currently after head
			
			head->next=newNode;  // Link head → newNode
			newNode->prev=head;   // Link newNode → head
			
			newNode->next=oldNode;    // Link newNode → oldNode
			oldNode->prev=newNode;		// Link oldNode → newNode
		}
		
		
		// Removes a given node from the doubly linked list
		void delNode(Node* oldNode){
			Node* oldprev=oldNode->prev;
			Node* oldnext=oldNode->next;
			
			oldprev->next=oldnext;    // Bypass oldNode
			oldnext->prev=oldprev;
		}
		
		// Inserts or updates a key-value pair in the cache , Moves the most recently used node to the front
		void putNode(int key , int val){
			
			if(m.find(key) != m.end()){   // If key already exists → remove old node and erase from map
				Node* oldNode=m[key];
				
				delNode(oldNode);
				m.erase(key);
			}
			 
			if(m.size() == limit){     // If cache is full → remove least recently used node (before tail)
				m.erase(tail->prev->key);
				delNode(tail->prev);
			}
			
			// Create and insert new node at the front (most recent position)
			Node* newNode=new Node(key , val);
			
			addNode(newNode);  
			m[key]=newNode;
		}
		
		
		// Returns value for given key and marks it as recently used
		int get(int key){
			
			if(m.find(key) == m.end()){   // If key doesn’t exist → return -1
				return -1;
			}
			
			 // Get the node and its value
			Node* ansNode=m[key];
			int ans=ansNode->val;
			
			
			// Move this node to the front (since it was just accessed)
			m.erase(key);
			delNode(ansNode);
		
			addNode(ansNode);
			m[key]=ansNode;
			
			return ans;  // Return value of key
		}
		
};



int main() {
    LRUCache l(3);   // Create LRU cache with capacity 3

    // Insert some values
    l.putNode(1, 10);
    l.putNode(2, 20);
    l.putNode(3, 30);

    // Cache is full now: [3,2,1] (most recent at front)
    cout << "Get 1 -> " << l.get(1) << endl;  // should return 10, order becomes [1,3,2]

    // Insert a new key (4), least recently used (key=2) should be evicted
    l.putNode(4, 40);
    cout << "Get 2 -> " << l.get(2) << endl;  // should return -1 (evicted)
    cout << "Get 3 -> " << l.get(3) << endl;  // should return 30

    // Insert another key (5), least recently used (key=1) should be evicted
    l.putNode(5, 50);
    cout << "Get 1 -> " << l.get(1) << endl;  // should return -1 (evicted)
    cout << "Get 4 -> " << l.get(4) << endl;  // should return 40
    cout << "Get 5 -> " << l.get(5) << endl;  // should return 50

    // Update an existing key (3 -> 300)
    l.putNode(3, 300);
    cout << "Get 3 -> " << l.get(3) << endl;  // should return 300 (updated)
}


