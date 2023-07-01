class Solution {
public:

    int solve(vector<vector<int>>& o,int n,int m,vector<vector<int>>& dp){
        if(n==0 && m==0 && o[n][m]!=1 ){
            return 1;
        }
        if(n<0 || m<0 || o[n][m]==1){
            return 0;
        }
        if(dp[n][m]!= (-1)) return dp[n][m];
        return dp[n][m] =  solve(o,n-1,m,dp) + solve(o,n,m-1,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size()-1;
        int m = o[0].size()-1;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        return solve(o,n,m,dp);
    }
};