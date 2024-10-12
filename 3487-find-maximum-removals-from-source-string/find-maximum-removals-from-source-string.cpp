class Solution {
public:
    unordered_map<int,bool> m; 
    int dp[3005][3005];
    int solve(string &s,string &p,int i,int j ){
        if(j==p.length() && i==s.length()) return 0;
        if(i==s.length()) return -100005;
        if(dp[i][j] != -1) return dp[i][j];
        int a =-100005 ,b=-100005,c=-100005;
        a = solve(s,p,i+1,j);
        if(m[i]){
        b = 1+solve(s,p,i+1,j);
        }
        if(s[i]==p[j]) c = solve(s,p,i+1,j+1);
        return dp[i][j] = max({a,b,c});
    }
    int maxRemovals(string s, string p, vector<int>& arr) {
        for(auto i:arr){
            m[i] = true;
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(s,p,0,0);
        return ans;
    }
};