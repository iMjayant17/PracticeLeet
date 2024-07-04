class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(auto i:coins){
            for(int j = 1;j<=amount;j++){
                if(j-i>=0){
                    dp[j]+=dp[j-i];
                }
            }
        }
        return dp[amount];
    }
};