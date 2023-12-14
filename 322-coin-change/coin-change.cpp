class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i = 0;i<amount+1;i++){
            dp[0][i] = INT_MAX;
        }
        dp[0][0] = 0;

        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<amount+1;j++){
                dp[i][j] = dp[i-1][j];

                if(j-coins[i-1]>=0 && dp[i][j-coins[i-1]]!=INT_MAX){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-coins[i-1]]);
                }
                
            }
        }
        if(dp[n][amount]==INT_MAX){
            return -1;
        }
        return dp[n][amount];
    }
};