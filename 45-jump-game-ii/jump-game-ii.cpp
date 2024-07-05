class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,100000);
        dp[0] = 0;
        for(int i = 1;i<n;i++){
            int cnt = 100000;
            for(int j =1;j<=1002;j++ ){
                if(i-j<0) break;
                if(nums[i-j]>=j) cnt = min(cnt,dp[i-j]);
            }
            dp[i] = cnt+1;
        }
        return dp[n-1];
    }
};