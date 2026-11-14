#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Solution{
	public:		
		bool isCycleDFS(int scr, vector<bool>&vis , vector<bool>&recPath, vector<vector<int>>&edges){
			vis[scr] = true;
			recPath[scr] = true;
			
			for(int i=0;i<edges.size(); i++){
				int u= edges[i][1];
				int v= edges[i][0];
				
				if(u == scr){
					if(!vis[v]){
						if(isCycleDFS(v, vis, recPath, edges)){
							return true;
						}
					}else if(recPath[v]){
						return true;
					}
				}
			}
			recPath[scr] = false;
			return false;
		}
		
		bool canFinish(int n, vector<vector<int>>& edges){
			vector<bool>vis(n,false);
			vector<bool>recPath(n, false);
			
			for(int i=0; i<n; i++){
				if(!vis[i]){
					if(isCycleDFS(i, vis, recPath, edges)){
						return false;
					}
				}
			}
			return true;
		}
};

int main(){
	vector<vector<int>>pre_req = {{1,0},{2,0},{3,1},{3,2}};
    int numCourse = 4;

    Solution s;

    if(s.canFinish(numCourse, pre_req)){
        cout << "You can finish all courses";
    }
    else{
        cout << "Cycle found — cannot finish all courses";
    }

    return 0;
}
