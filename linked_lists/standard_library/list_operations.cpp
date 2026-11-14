#include<iostream>
#include<list>

using namespace std;

int main(){
	list<int>l={1,3,5};
	
//	cout<<l[1]<<" outpot is 1\n";    is invalid
	
	cout<<l.front()<<endl;
	
	for(int e : l){
		cout<<e<<endl;
	}
	
	 // Add elements at the end
    l.emplace_back(2);
    l.emplace_front(3);
    l.push_back(90);
	cout<<"after\n";
	
	for(int e : l){
		cout<<e<<endl;
	}
	
	l.clear();
	
	cout<<"After deleting "<<l.size()<<endl;
}