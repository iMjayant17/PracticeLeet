class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i = 0;i<n;i++){
            if(!dp[i]) return false;
            for(int j = 1;j<=nums[i];j++){
                if(i+j>=n) break;
                dp[i+j] = true;
            }
        }
        return true;
    }
};