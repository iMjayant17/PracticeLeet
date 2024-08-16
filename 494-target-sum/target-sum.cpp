class Solution {
public:
    int dp[25][5000];
    int solve(vector<int>& nums, int idx , int target){
        if(idx==nums.size()){
            return target==0;
        }
        if(dp[idx][target+2000] != -1) return dp[idx][target+2000] ;
        int a = solve(nums,idx+1,target-nums[idx]);
        int b = solve(nums,idx+1,target+nums[idx]);
        return dp[idx][target+2000] = a+b;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,target);
    }
};