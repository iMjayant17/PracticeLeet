class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(); 
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans = 0;
        for(int len = 1;len<=s.length();len++){
            for(int i = 0,j = len-1;j<s.length();i++,j++){
                if(len==1){
                    dp[i][j] = true;
                    ans++;
                }
                else if(len==2){
                    if(s[i]==s[j]){
                         dp[i][j] = true;
                         ans++;
                    }     
                }
                else{
                   if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans++;
                   } 
                }
            }
        }
        return ans;
    }
};