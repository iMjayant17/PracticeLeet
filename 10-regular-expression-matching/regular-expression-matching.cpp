class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        bool dp[n+1][m+1];

        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i==0 && j==0){
                    dp[i][j] = true;
                }
                else if(i==0){
                    char c = p[j-1];
                    if(c!='*') dp[i][j] = false;
                    else dp[i][j] = dp[i][j-2];
                }
                else if(j==0){
                    dp[i][j] = false;
                }
                else{
                    if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                    else if(p[j-1]=='*'){
                        dp[i][j] = dp[i][j-2];

                        if(s[i-1]==p[j-2] || p[j-2]=='.'){
                            dp[i][j] |= dp[i-1][j];
                        }
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};