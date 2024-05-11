class Solution {
public:

    void dfs(unordered_map<int,vector<int>> &adj , 
    int node,vector<int> &value,bool &ans,int curr){
        if(value[node]!= -1){
            if(value[node]!=curr){
                ans = false;
            }
            return;
        }
        value[node] = curr;

        for(auto child:adj[node]){
            dfs(adj,child,value,ans,1-curr);
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int,vector<int>> adj;
        // vector<bool> visited(n+1,false);
        vector<int> value(n+1,-1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 1;i<=n;i++){
            if(value[i]==-1){
                bool ans = true;
                int curr = 0;

                dfs(adj,i,value,ans,curr);

                if(ans==false) return false;
            }
        }

        return true;

    }
};