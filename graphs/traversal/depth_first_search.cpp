#include<iostream>
#include<list>
#include<vector>

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
		
		void dfsHelper(int scr , vector<bool>&vis){
			cout<<scr<<" ";
			vis[scr] = true;
			
			for(int v: l[scr]){
				if(!vis[v]){
					dfsHelper(v,vis);
				}
			}
		}
		
		void dfs(){
			vector<bool>vis(V,false);
			
			for(int i=0;i<V ; i++){
				if(!vis[i]){
					dfsHelper(i,vis);
				}
			}
			cout<<endl;
		}		
};

int main(){
	Graph g(9);
	
	//Graph 1
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	
	//Graph 2
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(7,8);
	
	cout<<"Depth first search : ";
	g.dfs();
	
	return 0;
}