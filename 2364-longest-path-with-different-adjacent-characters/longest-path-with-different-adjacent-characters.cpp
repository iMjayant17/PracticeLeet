class Solution {
public:
    long long ans;

    long long solve(vector<vector<int>> &adj,int node,string &s , int par = -1){

        vector<long long> cnt(2,0);
        long long aaa = 0;

        for(auto child:adj[node]){
            if(child == par) continue;
            long long val = solve(adj,child,s,node);
            char ch = s[child];
            if(ch == s[node]){
                ans = max(ans,val);
            }else{
                ans = max(ans,val+1);
                cnt.push_back(val);
            }
        }
        sort(cnt.rbegin(),cnt.rend());
        ans = max(ans,cnt[0]+cnt[1]+1);
        return cnt[0]+1;
    }

    int longestPath(vector<int>& parent, string s) {
        ans = 0;
        long long n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        long long temp  = solve(adj,0,s);
        return ans;
    }
};