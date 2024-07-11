class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum&1) return false;
        int n = nums.size();
        int tar = sum>>1;
        vector<vector<bool>> dp(n+1,vector<bool>(tar+1,false));
        dp[0][0]  = true;
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<tar+1;j++){
                dp[i][j] = dp[i-1][j];
                if(j-nums[i-1]>=0) dp[i][j] = (dp[i-1][j-nums[i-1]]|dp[i][j]);
            }
        }
        return dp[n][tar];
    }
};