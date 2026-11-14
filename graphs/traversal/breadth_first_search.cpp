#include<iostream>
#include<list>
#include<vector>
#include<queue>

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
		
		void bst(int st){
			queue<int>q;
			vector<bool>vis(V , false);
			
			vis[st] = true;
			q.push(st);
			
			cout<<"BST Traversal in Graph :  ";
			while(q.size() > 0){
				int u = q.front();
				q.pop();
				
				cout<<u<<" ";
				
				for(int v: l[u]){
					if(!vis[v]){
						vis[v] = true;
						q.push(v);
					}
				}
			}
			cout<<endl;
		}
};

int main(){
	Graph g(5);
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	
	g.bst(0);
	
	return 0;
	
}