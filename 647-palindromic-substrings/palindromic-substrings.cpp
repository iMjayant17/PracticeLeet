class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans = 0;
        for(int length = 1;length<=n;length++){
            for(int i=0;i+length-1<n;i++){
                int j = i+length - 1;
                if(i==j){
                    dp[i][j] = true;
                }
                else if(i+1==j){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                    dp[i][j] = ((s[i]==s[j]) && dp[i+1][j-1]);
                }

                if(dp[i][j]==true) ans++;
            }
        }
        return ans;
    }
};