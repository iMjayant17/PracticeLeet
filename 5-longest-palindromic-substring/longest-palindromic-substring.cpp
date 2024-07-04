class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005];
        memset(dp,0,sizeof(dp));
        int n = s.length();
        int maxi = 0;
        int ind = 0;
        for(int diff = 0;diff<n;diff++){
            for(int i = 0,j = diff;j<n;i++,j++){
                if(diff==0){
                    dp[i][j] = 1;
                }
                else if(diff==1){
                    if(s[i]==s[j]) dp[i][j] = 2;
                }
                else{
                    if(dp[i+1][j-1]>0 && s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }

                if(maxi<dp[i][j]){
                   maxi = dp[i][j];
                    ind = i;
                }
            }
        }

        return s.substr(ind,maxi);
    }
};