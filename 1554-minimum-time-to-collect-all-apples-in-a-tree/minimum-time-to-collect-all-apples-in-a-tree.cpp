class Solution {
public:
    int dfs(vector<vector<int>> &adj,int node,vector<bool>& apple,int par = -1){

        int cnt = 0;
        for(auto child:adj[node]){
            if(child==par) continue;
            cnt+=dfs(adj,child,apple,node);
        }
        if(apple[node]==true || cnt>0){
            cnt+=2;
        }
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int ans = dfs(adj,0,hasApple);
        return ans==0 ? 0:ans-2;
    }
};