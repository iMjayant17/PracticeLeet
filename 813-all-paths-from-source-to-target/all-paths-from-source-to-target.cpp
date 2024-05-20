class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<vector<int>>& adj,int s,int d,vector<bool>& visited,vector<int> temp ={0}){
        if(s==d){

            result.push_back(temp);
            return;
        }
        if(visited[s]) return;

        for(auto child:adj[s]){
            temp.push_back(child);
            dfs(adj,child,d,visited ,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n);
        dfs(adj,0,n-1,visited);
        return result;
    }
};