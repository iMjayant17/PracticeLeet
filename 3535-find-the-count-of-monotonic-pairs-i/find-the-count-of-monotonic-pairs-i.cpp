class Solution {
public:
    const int M = 1e9 + 7;
    int dp[2005][60];
    int solve(vector<int>& nums, int idx, int last) {
        if (idx >= nums.size()) {
            return 1;
        }
        if(dp[idx][last]!= -1) return dp[idx][last];
        int ans = 0;
        for (int i = 0; i <= nums[idx]; i++) {
            int p1 = i, p2 = nums[idx] - i;
            int lastval1 = last;
            int lastval2 = 51-last;
            if (idx - 1 >= 0) {
                lastval2 = nums[idx-1] - last; 
            }
            if(p1>=lastval1 && p2<=lastval2){
                ans = (ans+ (solve(nums,idx+1,i))%M)%M;
            }
        }

        return dp[idx][last] =  ans%M;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};