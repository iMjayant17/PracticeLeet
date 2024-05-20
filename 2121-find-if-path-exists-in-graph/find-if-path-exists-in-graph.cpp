class Solution {
public:

    bool dfs(vector<vector<int>> &adj,int s,int d,vector<bool>& visited){
        if(visited[s]==true){
            return false;
        }
        if(s==d) return true;
        visited[s] = true;
        bool ans = false;
        for(auto child:adj[s]){
            if(visited[child]) continue;
            ans = (ans | dfs(adj,child,d,visited)); 
        }
        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        return dfs(adj,source,destination,visited);
    }
};