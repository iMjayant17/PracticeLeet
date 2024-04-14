class Solution {
public:
    // int ans = INT_MAX;
    // void dfs(vector<vector<int>>& grid, int i, int j, int cnt) {

    //     if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;
    //     if (grid[i][j] == 1) return;
    //     if ((i == grid.size() - 1) && (j == grid[0].size() - 1) &&
    //         grid[i][j] == 0){
    //         ans = min(ans, cnt);
    //         return;}
            
        
    //     grid[i][j] = 1;
    //     dfs(grid,i-1,j-1,cnt+1);
    //     dfs(grid,i-1,j,cnt+1);
    //     dfs(grid,i-1,j+1,cnt+1);
    //     dfs(grid,i,j-1,cnt+1);
    //     dfs(grid,i,j+1 ,cnt+1);
    //     dfs(grid,i+1,j-1,cnt+1);
    //     dfs(grid,i+1,j,cnt+1);
    //     dfs(grid,i+1,j+1,cnt+1);
    //     grid[i][j] = 0;
    // }

    //  leads to TLE ::::: always keep in mind that if it asks for minimum or shortest
    //  once try for BFS
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // dfs(grid, 0, 0, 1);
        // if (ans == INT_MAX)
        //     return -1;
        // return ans;
        int ans = 0;

        queue<pair<int,int>> q;
        if(grid[0][0]==1) return -1;

        q.push({0,0});
        grid[0][0] = 1;

        while(q.size()){
            ans++;
            int cnt = q.size();
            for(int l = 0;l<cnt;l++){

                auto [i,j] = q.front();
                if ((i == grid.size() - 1) && (j == grid[0].size() - 1)) return ans;
                q.pop();
                for(int x = -1;x<=1;x++){
                    for(int y = -1;y<=1;y++){
                        if(x==0 && y==0) continue;
                        int ii = i+x;
                        int jj = j+y;
    if (ii >= grid.size() || ii < 0 || jj >= grid[0].size() || jj < 0) continue;
    if (grid[ii][jj] == 1) continue;
    q.push({ii,jj});
    grid[ii][jj] = 1;
                    }
                }


            } 
        }


        return -1;
    }
};