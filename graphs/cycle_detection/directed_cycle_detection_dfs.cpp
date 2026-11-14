#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
	int V;
	list<int>*l;
	public:
		Graph(int V){
			this->V = V;
			l=new list<int>[V];
		}
		
		void addEdge(int u, int v){
			l[u].push_back(v);  
		}
		
		bool isCycleDirDFS(int u, vector<bool>&vis, vector<bool>&recPath){
			vis[u] = true;
			recPath[u] = true;
			
			for(int v: l[u]){
				if(!vis[v]){
					if(isCycleDirDFS(v,vis,recPath)){
						return true;
					}
				}
				else if(recPath[v]){  // cycle 
					return true;
				}
			}
			return false;
		}
		
		bool isCycle(vector<bool>& recPath){
			vector<bool>vis(V , false);
			
			
			for(int i=0; i<V; i++){
				if(!vis[i]){
					if(isCycleDirDFS(i , vis , recPath)){
						return true;
					}
				}
			}
			return false;
		}
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1); //creates a cycle

	vector<bool>recPath(4, false);
    if(g.isCycle(recPath))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

	for(bool is_true: recPath){
		cout<<is_true<<" ";
	}
    return 0;
}