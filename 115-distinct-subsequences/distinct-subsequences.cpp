class Solution {
public:
    int dp[1005][1005];
    int solve(int idx , int ind ,string &s,string &t){
        if(ind>=t.length()) return 1;
        if(idx>=s.length()) return 0;
        if(dp[idx][ind] != -1) return dp[idx][ind];
        int a = 0,b = 0;
        if(s[idx]==t[ind]){
            a = solve(idx+1,ind+1,s,t);
        }
            b = solve(idx+1,ind,s,t);

        return dp[idx][ind] = a+b;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};