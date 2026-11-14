#include<iostream>
#include<vector>
#include<deque>

using namespace std;

//void print_string_deque(string s , deque<string>dq){
//	cout<<s<<" : " ;
//	for(int i = 0 ; i< dq.size() ; i++){
//		cout<<dq[i]<<" , ";
//	}
//	cout<<endl;
//}
//	
//
//int main(){
//	deque<string>dq;
//	
//	dq.push_back("Ali");
//	dq.push_front("sara");
//	dq.push_back("Hamza");
//	
//	print_string_deque("Deque now" , dq);
//	
////	cout<<"Deque now : "<<endl;
////	for(int i = 0 ; i< dq.size() ; i++){
////		cout<<dq[i]<<" , ";
////	}
////	cout<<endl;
//	
//	dq.pop_back();
//	dq.pop_front();
//	
//	print_string_deque("Deque after removals " , dq);
//	
//}


class Deque{
	public:
		vector<string>v;
		
		bool is_empty(){
			return v.size() == 0;
		}
		
		void add_front(string s){
			v.insert(v.begin(), s);
		}
		
		void add_rear(string s){
			v.push_back(s);
		}
		
		string pop_at_front(){
			if (is_empty()){
				cout<<"Deque is empty ! underflow"<<endl;
				return "None";
			}  
			string val = v.front();   
        	v.erase(v.begin()); 
			return val;
		}
		
		string pop_at_back(){
			if (is_empty()){
				cout<<"Deque is empty ! underflow"<<endl;
				return "None";
			}
			
			string val = v[v.size() -1];
			v.pop_back();
			return val;
		}
		
		int size(){
			return v.size();
		}
		
		void print(){
			for(string s : v){
				cout<<s<<" , ";
			}
			cout<<endl;
		}
};

void show_state(string s , dq_obj){
	cout<<s<<endl;
	cout<<"deque is :" , dq_obj.print()<<endl;
	cout<<"Size : " , dq_obj.size()<<endl;
	cout<<"------------------------------------------------"<<endl;
}

int main(){
	Deque dq;
	show_state("Step 0 -> created empty deque ",dq);
}