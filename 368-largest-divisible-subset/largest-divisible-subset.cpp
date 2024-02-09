class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
            int maxi = 0;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    maxi = max(maxi,dp[j]);
                }
            }
            dp[i] = maxi + 1;
        }
        int idx = -1;
        int val = -1;
        for(int i = 0;i<dp.size();i++){
            if(val<dp[i]){
                val = dp[i];
                idx = i;
            }
        }

        int nums_val = nums[idx];
        // cout<<val<<" "<<idx<<endl;

        vector<int> ans;
        for(int i = idx;i>=0;i--){
            if((nums[i]%nums_val==0 || nums_val%nums[i]==0)  && (dp[i] == val)){
                ans.push_back(nums[i]);
                nums_val = nums[i];
                val--;
            }
        }

        return ans;
    }
};