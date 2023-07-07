class Solution {
public:

    int solve(vector<vector<char>>& matrix,int m,int n,int &maxi,vector<vector<int>> &dp){
        if(m>=matrix.size() || n>=matrix[0].size() ){
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];

        int right = 1+solve(matrix,m,n+1,maxi,dp);
        int diagonal = 1+solve(matrix,m+1,n+1,maxi,dp);
        int down = 1+solve(matrix,m+1,n,maxi,dp);
       
        if(matrix[m][n]=='1'){
            int ans = min({right,down,diagonal});
            maxi = max(maxi,ans);
            return dp[m][n] = ans;
        }
        else{
            return dp[m][n]= 0;
        }

        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        solve(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};