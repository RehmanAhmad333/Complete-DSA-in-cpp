#include<iostream>
#include<vector>

using namespace std;

class Solution{
	public:
		void dfs(vector<vector<int>>& image , int i ,  int j , int orgCol , int newCol , int n , int m){
			if(i<0 || j<0 || i>=n || j>=m || image[i][j] != orgCol || image[i][j] == newCol){
				return ;
			}
			
			image[i][j] = newCol;
			
			//Top
		    dfs(image , i-1 , j , orgCol ,newCol , n , m);
		    
		    //Bottom
		    dfs(image , i+1 , j , orgCol ,newCol , n , m);
		    
		    //Right
		    dfs(image , i , j+1 , orgCol, newCol , n , m);
		    
		    //Left
		    dfs(image , i , j-1 , orgCol,newCol , n , m);	
		}
		
		vector<vector<int>> floodFill (vector<vector<int>>& image , int i , int j , int color){
			int n = image.size();
			int m= image[0].size();
			
			dfs(image , i, j, image[i][j] , color , n , m);
			
			return image;
		}
};

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;   // starting row
    int sc = 1;   // starting column
    int newColor = 2;

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);

    cout << "Result:\n";
    for (auto &row : ans) {
        for (auto &pix : row) {
            cout << pix << " ";
        }
        cout << endl;
    }

    return 0;
}