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
		l =new  list<int>[V];
	}	
	
	void addEdge(int u , int v){
		l[u].push_back(v); // only directed graph 
	}
	
	void topoSort(){
		vector<int>result;
		
		// calculate indegrees
		vector<int>indeg(V , 0);
		for(int u=0; u<V ; u++){
			for(int v : l[u]){
				indeg[v]++ ;
			}
		}
		
		// 0 indeg nodes push in queue
		queue<int>q;
		for(int i=0; i<V; i++){
			if(indeg[i] == 0){
				q.push(i);
			}
		}
		
		// BFS
		while(q.size() > 0){
			int curr = q.front();
			q.pop();
			result.push_back(curr);
			
			for(int v : l[curr]){
				indeg[v]--;
				if(indeg[v] == 0){
					q.push(v);
				}
			}
		}
		
		if(result.size() == V){
			cout<<" Result  : ";
			for(int val : result){
				cout<<val<<" ";
			}
			cout<<endl; 
		}
		else{
            cout << "Topological Sort not possible (Graph has a cycle)\n"; 
		}
	}
};

int main() {
    Graph g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();
    
    Graph cg(4);

    cg.addEdge(0, 1);
    cg.addEdge(1, 2);
    cg.addEdge(2, 3);
    cg.addEdge(3, 1);   // ? cycle here (1 ? 2 ? 3 ? 1)

    cg.topoSort(); // This should print: Topological Sort not possible

    return 0;
}