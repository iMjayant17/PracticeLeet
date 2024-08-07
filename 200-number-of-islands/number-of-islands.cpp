class Solution {
public:


    void dfs(int i,int j ,vector<vector<char>>&grid,vector<vector<char>>&visited){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0){
            return;
        }
        if(grid[i][j]==visited[i][j] && visited[i][j]=='1'){
            visited[i][j]='0';
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
        }
        return;
        
    }


    int numIslands(vector<vector<char>>& grid) {

        vector<vector<char>>visited;
        visited = grid;
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==visited[i][j] && visited[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }

        return ans;
        
    }
};