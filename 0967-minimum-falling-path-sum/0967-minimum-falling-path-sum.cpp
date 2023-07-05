class Solution {
public:

    int solve(vector<vector<int>>& matrix,int n,int m,vector<vector<int>> &dp){
        
        if(n==matrix.size()-1){
            if(m>=0 && m<matrix.size()){
                return matrix[n][m];
            }
            return INT_MAX;
        }

        if(m<0 || m>=matrix.size()){
            return INT_MAX;
        }

        if(dp[n][m] != INT_MAX) return dp[n][m];

        int mini = INT_MAX ;

            mini=min(mini,solve(matrix,n+1,m-1,dp));
            mini=min(mini,solve(matrix,n+1,m,dp));
            mini=min(mini,solve(matrix,n+1,m+1,dp)); 

        return dp[n][m] = mini+matrix[n][m];
       
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<vector<int>> dp(n+5,vector<int>(n+5,INT_MAX));
        int mini = INT_MAX;
        for(int i = 0;i<matrix.size();i++){
            dp[0][i] = min(dp[0][i],(solve(matrix,0,i,dp)));
        }
        for(int i = 0;i<matrix.size();i++){
            mini = min(mini,dp[0][i]);
        }
        return mini;        
    }
};