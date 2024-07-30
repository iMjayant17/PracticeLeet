class Solution {
public:
    int dp[105][105];
    bool solve(string &s,int idx,int val){
        if(val<0) return false;
        if(idx==s.length()) return val==0;
        if(dp[idx][val] != -1) return dp[idx][val];
        bool ans = false;
        if(s[idx]=='('){
            ans |= solve(s,idx+1,val+1);
        }
        else if(s[idx]==')'){
            ans|= solve(s,idx+1,val-1);
        }
        else{
            ans |= solve(s,idx+1,val+1) || solve(s,idx+1,val-1) || solve(s,idx+1,val);
        }
        return dp[idx][val] = ans;
    }

    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};