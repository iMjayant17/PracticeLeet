class Solution {
public:
    int n;
    int dp[505][505][30];
    int solve(vector<int> &nums,int idx,int last,int k){
        if(idx>=n) return 0;

        if(dp[idx][last+1][k] != -1) return dp[idx][last+1][k];
        int p = 0,q = 0;
        int include= 0,exclude = 0;

       if(last == -1){
            include = 1 + solve(nums,idx+1,idx,k);
            exclude = solve(nums,idx+1,last,k);
       }
       else{
            if(nums[idx]==nums[last]){
                include = 1 + solve(nums,idx+1,idx,k);
                exclude = 0 + solve(nums,idx+1,last,k);
            }
            else{
                if(k>0) include = 1 + solve(nums,idx+1,idx,k-1);
                exclude = 0 + solve(nums,idx+1,last,k);

            }
       }

        return dp[idx][last+1][k] = max(include,exclude);

    }

    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,-1,k);


return ans;
    }
};