#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int>*l;
	
	public:
		Graph(int V){
			this->V = V;
			l = new list<int>[V];
		}
		
		void addEdge(int u , int v){
			l[u].push_back(v);
			l[v].push_back(u);
		}
		
		bool isCycleUndirDFS(int scr, vector<bool>&vis){
			queue<pair<int,int>>q;
			q.push({scr,-1});
			vis[scr] = true;
			
			while(!q.empty()){
				int u=q.front().first;
				int parU=q.front().second;
				q.pop();
				
				for(int v : l[u]){
					if(!vis[v]){
						q.push({v , u});
						vis[v] = true;
					}
					else if(v != parU){
							return true;
						}
				}
			}
			return false;
		}
		
		bool isCycle(){
			vector<bool>vis(V,false);
			
			for(int i=0; i<V ; i++){
				if(!vis[i]){
					if(isCycleUndirDFS(i , vis)){
						return true;
					}
				}
			}
			return false;
		}
};

int main(){
	Graph g1(6);
	
	//Graph with cycle
	g1.addEdge(0,1);
	g1.addEdge(0,3);
	g1.addEdge(0,2);
	g1.addEdge(2,0);
	g1.addEdge(3,4);
	
	if(g1.isCycle()){
		cout<<"Graph 1 has cycle.\n";
	}else{
		cout<<"Graph 1 has not cycle.\n";
	}
	
	Graph g2(5);
	//Graph with out cycle
	g2.addEdge(0,1);
	g2.addEdge(0,3);
	g2.addEdge(0,2);
	g2.addEdge(3,4);
	
	if(g2.isCycle()){
		cout<<"Graph 2 has cycle.\n";
	}else{
		cout<<"Graph 2 has not cycle.\n";
	}
}