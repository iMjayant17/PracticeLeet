class Solution {
public:

    void dfs(vector<vector<int>> &adj,int node,vector<bool>& visited){
        if(visited[node]){
            return;
        }
        visited[node] = true;
        for(auto child:adj[node]){
            dfs(adj,child,visited);
        }

    }

    int makeConnected(int n, vector<vector<int>>& con) {

        if(con.size()<n-1) return -1;

        vector<vector<int>> adj(n);

        for(auto it:con){
            int ff = it[0];
            int ss = it[1];
            adj[ff].push_back(ss);
            adj[ss].push_back(ff);
        }

        vector<bool> visited(n,false);
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                ans++;
            }
        }
        return ans;

    }
};