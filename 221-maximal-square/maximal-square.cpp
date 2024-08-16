class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                dp[i][j] = 0;
                if(j==0 || i==0){
                    if(matrix[i][j]=='1') dp[i][j] = 1;
                    
                }
                else{
                    if(matrix[i][j]=='1'){
                        dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                    }
                }
                ans = max(ans,dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
    
        return ans*ans;
    }
};