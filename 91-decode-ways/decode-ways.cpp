class Solution {
public:
    int dp[1000];
    int solve(int idx ,string &s){
        if(idx>=s.length()){
            return 1;
        }
        if(s[idx]=='0') return 0;

        if(dp[idx]!= -1) return dp[idx];
        int a = 0 ,b = 0;
        a = solve(idx+1,s);
        string t = "";
        t.push_back(s[idx]);
        if(idx+1<s.length()){
            t.push_back(s[idx+1]);
            if(stoi(t)<=26 && stoi(t)>0){
            b =solve(idx+2,s);
        }
        }
        

        return dp[idx] = a+b;

    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};