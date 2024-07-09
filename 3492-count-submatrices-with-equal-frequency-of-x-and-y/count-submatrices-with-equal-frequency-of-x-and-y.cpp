class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        vector<vector<pair<int, int>>> arr(n, vector<pair<int, int>>(m, {0, 0}));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (i - 1 >= 0)
                    arr[i][j].first += arr[i - 1][j].first,
                        arr[i][j].second += arr[i - 1][j].second;
                if (j - 1 >= 0)
                    arr[i][j].first += arr[i][j - 1].first,
                        arr[i][j].second += arr[i][j - 1].second;
                if (i - 1 >= 0 && j - 1 >= 0)
                    arr[i][j].first -= arr[i - 1][j - 1].first,
                        arr[i][j].second -= arr[i - 1][j - 1].second;
                if (grid[i][j] == 'X') {
                    arr[i][j].first++;
                } else if (grid[i][j] == 'Y') {
                    arr[i][j].second++;
                }

                if (arr[i][j].first == arr[i][j].second && arr[i][j].first > 0)
                    ans++;
            }
        }

        return ans;
    }
};