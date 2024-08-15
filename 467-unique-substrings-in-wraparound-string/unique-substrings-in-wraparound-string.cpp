class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int> dp(26,0);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(i==0){
                cnt = 1;
                dp[s[i]-'a'] = cnt;
            }
            else{
                if((s[i]-s[i-1]-1)%26 == 0){
                    cnt++;
                }
                else{
                    cnt = 1;
                }
                dp[s[i]-'a'] = max(dp[s[i]-'a'],cnt);
            }
        }
        return accumulate(dp.begin(),dp.end(),0ll);
    }
};