class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int dp[n][m];

        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j>=0; j--) {
                if (i == n-1 && j == m-1) {
                    dp[i][j] = max(1, 1 - A[i][j]);
                } else if (i == n-1) {
                    dp[i][j] = max(1, dp[i][j + 1] - A[i][j]);
                } else if (j == m-1) {
                    dp[i][j] = max(1, dp[i + 1][j] - A[i][j]);
                } else {
                    dp[i][j] =
                        max(1, min(dp[i][j + 1], dp[i + 1][j]) - A[i][j]);
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[0][0];
    }
};