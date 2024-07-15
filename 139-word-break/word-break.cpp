class Solution {
public:
    
    
    bool solve(int idx,string s ,unordered_set<string> &m,vector<int> &dp){
        if(idx==s.length()){
            return true;
        }
        if(dp[idx]!= -1) return dp[idx];
        for(int i = idx;i<s.length();i++){
            if(m.count(s.substr(idx,i-idx+1)) && solve(i+1,s,m,dp)) {
                 return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(0,s,m,dp);
    }
};