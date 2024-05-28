class Solution {
public:
    int dfs(unordered_map<int,vector<pair<int,int>>> &adj,vector<bool > &visited,int node,int par = -1){
        
        if(visited[node]) return INT_MAX;
        int ans = INT_MAX;
        visited[node] = true;
        for(auto child:adj[node]){
            if(child.first == par) continue;
            int temp = dfs(adj,visited,child.first,node);
            ans = min({ans,temp,child.second}); 
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<bool> visited(n+5,false);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        return dfs(adj,visited,1);
    }
};