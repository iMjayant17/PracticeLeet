class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        bool dp[n+1][m+1];

        for(int i = n;i>=0;i--){
            for(int j = m;j>=0;j--){
                if(i==n && j==m){
                    dp[i][j] = true;
                }
                else if(j==m){
                    dp[i][j] = false;  
                }
                else if(i==n){
                    if(p[j]=='*'){
                        dp[i][j] = dp[i][j+1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i]==p[j] || p[j]=='?') dp[i][j] = dp[i+1][j+1];
                    else if(p[j]=='*'){
                        dp[i][j] = false;
                        dp[i][j] = (dp[i+1][j] | dp[i][j+1]);
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[0][0];
    }
};