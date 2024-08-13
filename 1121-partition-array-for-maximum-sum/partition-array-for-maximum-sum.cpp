class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int maxi = arr[i];
            for (int j = i; j >= 0; j--) {
                if (i - j + 1 > k)
                    break;
                maxi = max(maxi, arr[j]);
                dp[i] = max(dp[i],
                            (j - 1 >= 0 ? dp[j - 1] : 0) + (i - j + 1) * maxi);
            }
            cout << endl;
        }
        return dp[n - 1];
    }
};
