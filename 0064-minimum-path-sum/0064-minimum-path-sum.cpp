class Solution {
public:

    int solve(vector<vector<int>>& grid,int n,int m, vector<vector<int>> & dp){
        cout<<n<<" "<<m<<endl;
        if(n==0 && m==0){
            return grid[0][0];
        }
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans = grid[n][m]+min(solve(grid,n-1,m,dp),solve(grid,n,m-1,dp));
        cout<<ans<<"for"<<n<<" "<<m<<endl;
       dp[n][m]= ans;
       return dp[n][m];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // int dp[n+1][m+1]={-1};
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        cout<<n<<" "<<m<<endl;
        return solve(grid,n-1,m-1,dp);
    }
};