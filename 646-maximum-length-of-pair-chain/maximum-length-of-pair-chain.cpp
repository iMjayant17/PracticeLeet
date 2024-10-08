class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int maxi = 0;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    maxi = max(maxi, dp[j]);
                }
            }
            dp[i] += maxi;
        }
        return dp[n-1];
    }
};