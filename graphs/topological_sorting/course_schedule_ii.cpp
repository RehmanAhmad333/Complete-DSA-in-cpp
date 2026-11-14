#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool isCycleDFS(int scr , vector<bool>&vis, vector<bool>&recPath, vector<vector<int>>&edges){
	vis[scr] = true;
	recPath[scr] = true;
	
	for(int i=0; i<edges.size(); i++){
		int v= edges[i][0];
		int u= edges[i][1];
		
		if(u == scr){
			if(!vis[v]){
				if(isCycleDFS(v , vis , recPath, edges)){
					return true;
				}
			}else if(recPath[v]){  // BACK EDGE - cycle
				return true;
			}
		}
	}
	
	recPath[scr] = false;
	return false;
}

void topoSort(int scr , vector<bool>&vis , stack<int>&s , vector<vector<int>>& edges){
	vis[scr] = true;
	
	for(int i=0; i<edges.size(); i++){
		int v= edges[i][0];
		int u= edges[i][1];
		
		if(u == scr){
			if(!vis[v]){
				topoSort(v, vis, s , edges);
			}
		}
	}
	s.push(scr);
}

vector<int> findOrder(int n, vector<vector<int>> edges){
	vector<bool>vis(n,false);
	vector<bool>recPath(n,false);
	vector<int>ans;
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			if(isCycleDFS(i , vis, recPath , edges)){
				return ans;
			}
		}
	}
	
	//Topological sort order -DAG
	stack<int>s;
	vis.assign(n, false);
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			topoSort(i, vis , s , edges);
		}
	}
	
	while(s.size() > 0){
		ans.push_back(s.top());
		s.pop();
	}
	
	return ans;
}

int main(){
	int numCourse = 4;
	vector<vector<int>> pre_req = {{1,0},{2,0},{3,1},{3,2}};
	
	vector<int>order = findOrder(numCourse , pre_req);

    cout<<"Topological Order: ";
    for(int x : order){
        cout<< x << " ";
    }
    cout<< endl;

    return 0;
}