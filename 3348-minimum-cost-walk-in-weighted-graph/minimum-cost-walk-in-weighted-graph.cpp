class Solution {
public:

    map<int,int> value;
    map<int,int> grp;

    int dfs(vector<vector<pair<int,int>>> &adj,vector<bool> &vis,int node,int c){
        vis[node] = true;
        grp[node] = c;
        int ans = INT_MAX;
        for(auto i:adj[node]){
            int val;
            if(vis[i.first]) val = INT_MAX;
            else val = dfs(adj,vis,i.first,c);
            ans = (ans&val&i.second);
        }
        return ans;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            if(vis[i]) continue;
            int val = dfs(adj,vis,i,i);
            value[i] = val;
        }
        vector<int> ans;
        for(auto i:query){
            if(i[0]==i[1]) ans.push_back(0);
            else if(grp[i[0]]==grp[i[1]]) ans.push_back(value[grp[i[0]]]);
            else ans.push_back(-1);
        }
        return ans;

    }
};