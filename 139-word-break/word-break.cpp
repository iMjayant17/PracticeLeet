class Solution {
public:
    unordered_map<string,bool> m;
    int dp[1005];
    bool solve(int idx,string &s){
        if(idx>=s.length()){
            return true;
        }
        if(dp[idx]!= -1) return dp[idx];
        string k = "";
        for(int i = idx;i<s.length();i++){
            k.push_back(s[i]);
            if(m.find(k)!=m.end()){
                bool p = solve(i+1,s);
                if(p) return dp[idx] = p;
            } 
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict){
            m[i] = true;
        }
        
        return solve(0,s);

    }
};