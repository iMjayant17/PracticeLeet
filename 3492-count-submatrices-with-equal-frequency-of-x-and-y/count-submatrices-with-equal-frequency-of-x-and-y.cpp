class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (i - 1 >= 0)
                    dp[i][j].first += dp[i - 1][j].first,
                        dp[i][j].second += dp[i - 1][j].second;
                if (j - 1 >= 0)
                    dp[i][j].first += dp[i][j - 1].first,
                        dp[i][j].second += dp[i][j - 1].second;
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j].first -= dp[i - 1][j - 1].first,
                        dp[i][j].second -= dp[i - 1][j - 1].second;
                if (grid[i][j] == 'X') {
                    dp[i][j].first++;
                } else if (grid[i][j] == 'Y') {
                    dp[i][j].second++;
                }

                if (dp[i][j].first == dp[i][j].second && dp[i][j].first > 0)
                    ans++;
            }
        }

        return ans;
    }
};