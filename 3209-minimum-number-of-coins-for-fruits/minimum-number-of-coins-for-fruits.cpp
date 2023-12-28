class Solution {
public:
    int minimumCoins(vector<int>& p) {
        int n  = p.size();
        vector<int> dp(n+5,INT_MAX);
        dp[0] = p[0];
        dp[1] = p[0];
        for(int i = 1;i<n;i++){
            // if(dp[i]==INT_MAX) dp[i] = p[i];
            for(int j =i;j<min((2*(i+1)),n);j++ ){
                // cout<<dp[j]<<" ";
                dp[j] = min(dp[i-1]+p[i],dp[j]);
                // cout<<dp[j]<<endl;
            }
        }
        // for(auto i:dp) cout<<i<<" ";
        return dp[n-1];
    }
};