class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // x+y = sum
        // x-y = target
        // 2x = sum+target
        // dp[i][j] = ith coin use krk jth sum bnane k ways

        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if((sum+target)&1) return 0;
        int tar = (sum+target)/2;
        int n = nums.size();
        vector<map<int,int>> dp(n+1); // special part...dimaag khraab
        dp[0][0] = 1;
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<tar+1;j++){
                dp[i][j] += dp[i-1][j];
                if(j-nums[i-1]>=0) dp[i][j] += dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][tar];


    }
};