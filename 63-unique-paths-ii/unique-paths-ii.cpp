class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 0;

                if (A[i][j] == 1)
                    continue;

                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[n-1][m-1];
    }
};