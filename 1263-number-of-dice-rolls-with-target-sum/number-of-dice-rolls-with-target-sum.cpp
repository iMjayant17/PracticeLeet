class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        long long M = 1e9+7;
        vector<vector<long long>> dp(n+1,vector<long long> (target+1,0));
        dp[0][0] = 1;
        for(long long i = 1;i<n+1;i++){
            for(long long j =1;j<target+1;j++){
                for(long long p = 1;p<=k;p++){
                    if(j-p<0) continue;
                    long long val = (dp[i][j]+ dp[i-1][j-p])%M;
                    dp[i][j] = val;
                    dp[i][j] = dp[i][j]%M;
                }
            }
        }

        return (int) dp[n][target]%M;
    }
};