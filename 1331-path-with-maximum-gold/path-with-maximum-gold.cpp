class Solution {
public:
    int solve(int i  , int  j , vector<vector<int>> &g , vector<vector<int>> &vis){
        
        if(i >= g.size() || i < 0 || j < 0 || j >= g[0].size() || vis[i][j] == 1 || g[i][j] == 0){
            return 0;
        }

        vis[i][j] = 1;

        int left = g[i][j] + solve(i , j-1, g , vis);
        int right = g[i][j] + solve(i , j+1 , g  , vis);
        int top = g[i][j] + solve(i-1 , j  , g , vis);
        int bot = g[i][j] + solve(i+1 , j , g, vis);

        vis[i][j] = 0;

        return max({left , right , top , bot});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int mx =0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) continue;
                vector<vector<int>>  vis(n , vector<int> (m , 0));

                int ans = solve(i , j , grid , vis);
                mx  = max(ans  , mx);

            }
        }
        return mx;

    }
};