class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<=amount;i++){
            for(auto j:coins){
                if(i-j>=0 && dp[i-j]!=INT_MAX){
                    dp[i] = min(dp[i-j]+1 , dp[i]);
                }
            }
        }
        return dp[amount]==INT_MAX? -1:dp[amount];
    }
};