class Solution {
public:
    int m[2];
    const int M = 1e9+7;
    vector<int> arr, brr;
    unordered_map<int, int> f, s;
    long long dp[100009][3];
    long long solve(int idx, int grp) {
        if (idx >= m[grp])
            return 0;
        if (dp[idx][grp] != -1)
            return dp[idx][grp];
        long long take = 0, not_take = 0;
        if (grp == 0) {
            take = (arr[idx] + solve(idx + 1, grp));
            if (s.find(arr[idx]) != s.end()) {
                not_take = (arr[idx] + solve(s[arr[idx]] + 1, 1 - grp));
            }
        } else {
            take = (brr[idx] + solve(idx + 1, grp));
            if (f.find(brr[idx]) != f.end()) {
                not_take = (brr[idx] + solve(f[brr[idx]] + 1, 1 - grp));
            }
        }
        return dp[idx][grp] = max(take, not_take);
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        arr = nums1;
        brr = nums2;
        for (int i = 0; i < nums1.size(); i++) {
            f[nums1[i]] = i;
        }
        m[0] = nums1.size();
        for (int i = 0; i < nums2.size(); i++) {
            s[nums2[i]] = i;
        }
        m[1] = nums2.size();
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(0, 0)%M;
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(0, 1)%M;
        return max(ans1, ans2);
    }
};