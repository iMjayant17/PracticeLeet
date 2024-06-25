class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> m;
        vector<int> arr;
        arr.push_back(nums[0]);
        m[nums[0]]+=nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!= arr.back()){
                arr.push_back(nums[i]);
            }
            m[nums[i]]+=nums[i];
        }

        int n = arr.size();
        vector<int> dp(n,0);
        dp[0] = m[arr[0]];
        for(int i = 1;i<n;i++){
            if(arr[i-1]+1 == arr[i]){
                dp[i] = max(dp[i-1],((i-2>=0) ? dp[i-2]:0) + m[arr[i]]);
            }
            else{
                dp[i] = dp[i-1] + m[arr[i]];
            }
        }

        // for(auto i:dp){
        //     cout<<i<<" ";
        // }

        return dp[n-1];
    }
};