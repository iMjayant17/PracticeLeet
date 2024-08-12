class Solution {
public:
    const int M = 1e9+7;
    int dp[2005][55][55];
    int solve(vector<int>& nums,int idx,int last_inc, int last_dec){
        if(idx>=nums.size()) return 1;
        if(dp[idx][last_inc][last_dec] != -1) return dp[idx][last_inc][last_dec];
        int  ans = 0;
        for(int i = 0;i<=nums[idx];i++){
            int val1 = i;
            int val2 = nums[idx]-val1;
            if(val1>=last_inc && val2<=last_dec){
                ans = (ans + solve(nums,idx+1,val1,val2)%M)%M; 
            }
        }
        return dp[idx][last_inc][last_dec] = ans%M;
    }

    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,51);
    }
};