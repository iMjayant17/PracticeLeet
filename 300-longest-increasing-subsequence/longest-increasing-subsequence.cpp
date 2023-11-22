class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 1;i<n;i++){
            int val = 1;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    val = max(val,dp[j]+1);
                }
            }
            dp[i] = val;
        }
        int maxi = *max_element(dp.begin(),dp.end());
            return maxi;
    }
};