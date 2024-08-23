class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        int n = nums.size();
        int dp[n][k + 1];
        vector<map<int, int>> m(k + 1);
        vector<int> maxi(k + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = m[j][nums[i]]+1;
                if (j - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if (j - 1 >= 0) {
                    dp[i][j] = max(1+maxi[j - 1], dp[i][j]);
                    maxi[j - 1] = max(maxi[j - 1], dp[i][j - 1]);
                }
                m[j][nums[i]] = dp[i][j];

                if(j==k) ans = max(ans,dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            // for(auto ii:maxi){
            //     cout<<ii<<"_";
            // }
            // cout<<endl;
        }


        return ans;
    }
};