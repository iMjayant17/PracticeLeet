class Solution {
public:

    // int solve(vector<vector<int>>& grid,int n,int m, vector<vector<int>> & dp){
    //     cout<<n<<" "<<m<<endl;
    //     if(n==0 && m==0){
    //         return grid[0][0];
    //     }
    //     if(n<0 || m<0) return INT_MAX;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     int ans = grid[n][m]+min(solve(grid,n-1,m,dp),solve(grid,n,m-1,dp));
    //     cout<<ans<<"for"<<n<<" "<<m<<endl;
    //    dp[n][m]= ans;
    //    return dp[n][m];
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // // int dp[n+1][m+1]={-1};
        // vector<vector<int>> dp(n+1,vector<int>(m,));
        // cout<<n<<" "<<m<<endl;
        // return solve(grid,n-1,m-1,dp);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int mini =INT_MAX; 
                if(i-1>=0) mini = min(mini,grid[i-1][j]);
                if(j-1>=0) mini = min(mini,grid[i][j-1]);
                if(mini != INT_MAX){
                    grid[i][j]+=mini;
                }
            }
        }
        return grid[n-1][m-1];
    }
};