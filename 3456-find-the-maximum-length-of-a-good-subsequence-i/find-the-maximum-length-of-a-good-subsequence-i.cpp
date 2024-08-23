class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int dp[n][k+1];
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=k;j++){
                int maxi = 0;
                for(int l = 0;l<i;l++){
                    if(nums[i]==nums[l]){
                        maxi = max(maxi,dp[l][j]);
                    }
                    else{
                        if(j-1>=0) maxi = max(maxi,dp[l][j-1]);
                    }
                }
                
                dp[i][j] = 1 + maxi;
                if(j-1>=0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
                if(j==k) ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};