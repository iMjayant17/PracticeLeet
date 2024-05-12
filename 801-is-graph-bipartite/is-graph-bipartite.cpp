class Solution {
public:

    void dfs(vector<vector<int>>& adj,int src,vector<int> &value,bool &ans,int cnt = 0){
        if(value[src]!= -1){
            if(value[src]!=cnt){
                ans = false;
            }
            return;
        }
        value[src] = cnt;

        for(auto child:adj[src]){
            dfs(adj,child,value,ans,1-cnt);
        }
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> value(n+1,-1);
        for(int i = 0;i<n;i++){
            if(value[i]== -1){
                bool ans = true;
                dfs(adj,i,value,ans);
                if(ans == false){
                    return false;
                }
            }
        }

        return true;
    }
};