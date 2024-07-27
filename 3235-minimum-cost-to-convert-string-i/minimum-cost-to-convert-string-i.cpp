class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
    if (s.length() != t.length()) return -1;

    vector<vector<long long>> dp(26, vector<long long>(26, 1e12));
    dp[0][0]=0;
      for(int i=0;i<26;i++) dp[i][i]=0;
    int n = o.size();
    for (int i = 0; i < n; ++i) {
        dp[o[i] - 'a'][c[i] - 'a'] = min(dp[o[i] - 'a'][c[i] - 'a'], (long long)(cost[i]));
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dp[i][k] == 1e12 || dp[k][j] == 1e12) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    long long ans = 0;
    int m = s.size();

    for (int i = 0; i < m; ++i) {
        long long diff = dp[s[i] - 'a'][t[i] - 'a'];
      
        if (diff == 1e12) {
            return -1; 
        }
        ans += diff;
    }

    return ans;
} 
};