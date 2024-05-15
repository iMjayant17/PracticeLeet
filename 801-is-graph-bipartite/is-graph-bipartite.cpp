class Solution {
public:
    bool finalans;

    void dfs(int node,vector<vector<int>>& adj,vector<int> &visited,int st){
        if(visited[node]!= -1){
            if(visited[node]!=st){
                finalans = false;
            }
            return;
        }
        visited[node] = st;
        for(auto child:adj[node]){
            dfs(child,adj,visited,1 - st);
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        finalans = true; 
        int n = adj.size();
        vector<int> visited(n,-1);

        for(int i = 0;i<n;i++){
            if(visited[i]== -1){
                dfs(i,adj,visited,0);
            }
        }

        if(finalans){
            return true;
        }
        return false;
    }
};