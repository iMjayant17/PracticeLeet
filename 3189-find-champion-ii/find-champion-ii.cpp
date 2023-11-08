class Solution {
public:
    
    void dfs(int node , vector<bool> &vis,int par,vector<int> adj[]){
        if(vis[node]==true) return;
        vis[node] = true;
        for(auto child :adj[node] ){
            if(child==par) continue;
            dfs(child,vis,node,adj);
        }
    }
    
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i = 0;i<n;i++){
            vector<bool> vis(n,false);
            dfs(i,vis,-1,adj);
            sort(vis.begin(),vis.end());
            
            if(vis[0]==true){
                return i; 
            }
            
            
        }
       
        return -1;
    }
};