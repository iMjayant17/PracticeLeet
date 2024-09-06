class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        int dp[n][n];
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = diff; j < n; j++, i++) {
                if (diff == 0) {
                    dp[i][j] = 1;
                } else if (diff == 1) {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                } else {
                    bool val = 0;
                    if (s[i] == s[j]) val =  dp[i + 1][j - 1];
                    dp[i][j] = val;
                }
            }
        }
        int ans[n];
        ans[0] = 0;
        for(int i = 1;i<n;i++){
            int val = INT_MAX;
            for(int j = i;j>=0;j--){
                if(dp[j][i]){
                    if(j-1>=0){
                        val = min(val,ans[j-1]);
                    }
                    else val = min(val,-1);
                    
                }
            }
            ans[i] = val+1;
        }
        return ans[n-1];
    }
};

/*
      a  a  a  a  b  b  b  a  b  a  b  a
  a   0  0  0  0  1  2  3  3  4  3  4  3
  a  -1  0  0  0  1  2  3  2  3  2  3  2
  a  -1 -1  0  0  1  2  2  1  2  1  2  2
  a  -1 -1 -1  0  1  1  1  0  1  1  2  2
  b  -1 -1 -1 -1  0  0  0  1  1  2  2  3
  b  -1 -1 -1 -1 -1  0  0  1  1  2  1  2
  b  -1 -1 -1 -1 -1 -1  0  1  0  1  0  1
  a  -1 -1 -1 -1 -1 -1 -1  0  1  0  1  0
  b  -1 -1 -1 -1 -1 -1 -1 -1  0  1  0  1
  a  -1 -1 -1 -1 -1 -1 -1 -1 -1  0  1  0
  b  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1  0  1
  a  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1  0

*/