class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n = nums.size();
        // vector<bool> dp(n,false);
        // dp[0] = true;
        // for(int i = 0;i<n;i++){
        //     if(!dp[i]) return false;
        //     for(int j = 1;j<=nums[i];j++){
        //         if(i+j>=n) break;
        //         dp[i+j] = true;
        //     }
        // }
        // return true;
        int n = nums.size();
        if(n==1) return true;
        int maxi = nums[0];
        for(int i = 1;i<n;i++){
            if(i>maxi) return false;
            maxi = max(maxi,i+nums[i]);
        }
        return true;
    }
};