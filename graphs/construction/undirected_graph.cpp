#include<iostream>
#include<list>

using namespace std;

class Graph{
	int V;
	list<int> *l;
	
	public:
		Graph(int V){
			this->V = V;
			l = new list<int>[V];
		}
		
		void addEdge(int a , int b){
			l[a].push_back(b);
			l[b].push_back(a);
		}
		
		void print(){
			cout<<"Graph : "<<endl;
			for(int i= 0; i<V ; i++){
				cout<<i<<" : ";
				for(int neighNode : l[i]){
					cout<<neighNode<<" ";
				}
				cout<<endl;
			}
			return;
		}
};

int main(){
	Graph g(5);
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(2,4);
	
	g.print();
	return 0;
}