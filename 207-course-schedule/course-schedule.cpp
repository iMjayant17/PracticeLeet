class Solution {
public:

    bool dfs(vector<int> adj[] , int node,vector<bool> &visited , vector<bool> &inRecur){
        
        visited[node] = true;
        inRecur[node] = true;
        for(auto child : adj[node]){
            if(!visited[child] && dfs(adj,child,visited,inRecur)){
                return true;
            }
            else if(inRecur[child]) return true;
        }
        inRecur[node] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<bool > visited(2005,false) , inRecur(2005,false);
        for(auto i:pre){
            adj[i[0]].push_back( i[1]);
        }
        for(int i = 0;i<n;i++){
            if(visited[i]==false &&  dfs(adj,i,visited,inRecur)) return false;
        }
        return true;

    }
};