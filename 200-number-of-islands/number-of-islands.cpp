class Solution {
public:


    void solve(int i,int j ,vector<vector<char>>&grid,vector<vector<char>>&visited){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0){
            return;
        }
        if(grid[i][j]==visited[i][j] && visited[i][j]=='1'){
            visited[i][j]='0';
        solve(i+1,j,grid,visited);
        solve(i-1,j,grid,visited);
        solve(i,j+1,grid,visited);
        solve(i,j-1,grid,visited);
        }
    
        
    }


    int numIslands(vector<vector<char>>& grid) {

        vector<vector<char>>visited;
        visited = grid;
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==visited[i][j] && visited[i][j]=='1'){
                    ans++;
                    solve(i,j,grid,visited);
                }
            }
        }

        return ans;
        
    }
};