class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n];
        dp[0] = (s[0]=='0')?0:1;
        for(int i = 1;i<n;i++){
            dp[i] = 0;
            if(s[i]!='0') dp[i] += dp[i-1];
            if(s.substr(i-1,2)>"00" && s.substr(i-1,2)<="26" && s[i-1]!='0'){
                if(i-2>=0) dp[i]+=dp[i-2];
                else dp[i]++;
            }
        }
        // cout<<s.substr(0,2)<<endl;;
        return dp[n-1];
    }
};