class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i<n;i++){
            for(int j =i;j<=min(n-1,i+nums[i]);j++ ){
                dp[j] = min(dp[j],1+dp[i]);
            }
        }
        return dp[n-1];
    }
};