class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            int val = INT_MAX;
            for(int j = 1;j*j<=i;j++){
                val = min(val,dp[i-(j*j)]);
            }
            dp[i] = val+1;
        }
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        return dp[n];


    }
};