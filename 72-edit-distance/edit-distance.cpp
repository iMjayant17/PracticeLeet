class Solution {
public:
int lcs(string s,string t){
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                             //replace       //delete        //insert
    return dp[m][n];
}
    int minDistance(string s, string t) {
        return lcs(s,t) ;
    }
};