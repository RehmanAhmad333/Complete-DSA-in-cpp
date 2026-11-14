#include<iostream>
#include<vector>

using namespace std;

void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&grid, int n, int m){
	if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != '1' || vis[i][j] == true){
		return;
	}
	
	vis[i][j] = true;
	
	dfs(i , j+1 , vis , grid, n, m); //right
	dfs(i , j-1 , vis , grid, n, m); //left
	dfs(i+1 , j , vis , grid, n, m); //bottom
	dfs(i-1 , j , vis , grid, n, m); //top
}

int numIslands(vector<vector<char>>& grid){
	int n=grid.size();
	int m=grid[0].size();
	
	int islands = 0;
	
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] == '1' && !vis[i][j]){
				dfs(i,j,vis,grid,n,m);
				islands++;
			}
		}
	}
	return islands;	
}
int main(){
//Example 1:
	vector<vector<char>> grid_1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
	
	int islands = numIslands(grid_1);
	cout<<"Grid 1 has "<< islands << " numbers of Islands.\n";
	
//Example 2:
	vector<vector<char>> grid_2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
	
	cout<<"Grid 2 has "<< numIslands(grid_2) << " numbers of Islands.\n";

	return 0;
}