class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][nums[0]%3] = nums[0];
        for(int i = 1;i<n;i++){
            dp[i][(dp[i-1][0]+nums[i])%3] = max(dp[i][(dp[i-1][0]+nums[i])%3],dp[i-1][0]+nums[i]);
            dp[i][(dp[i-1][1]+nums[i])%3] = max(dp[i][(dp[i-1][1]+nums[i])%3],dp[i-1][1]+nums[i]);
            dp[i][(dp[i-1][2]+nums[i])%3] = max(dp[i][(dp[i-1][2]+nums[i])%3],dp[i-1][2]+nums[i]);
            dp[i][0] = max(dp[i-1][0],dp[i][0]);
            dp[i][1] = max(dp[i-1][1],dp[i][1]);
            dp[i][2] = max(dp[i-1][2],dp[i][2]);
        }
        return dp[n-1][0];
    }
};