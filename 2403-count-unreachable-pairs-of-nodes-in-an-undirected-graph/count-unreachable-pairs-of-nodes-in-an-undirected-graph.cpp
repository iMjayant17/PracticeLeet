class Solution {
public:
    long long dfs(vector<vector<int>> &adj,int node,vector<bool> &visited){
        if(visited[node]){
            return 0;
        }
        visited[node] = true;
        long long ans = 0;
        for(auto child:adj[node]){
            long long temp = dfs(adj,child,visited);
            ans+=temp;
        }
        return 1+ans;

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);

        for(auto ed:edges){
            int ff = ed[0];
            int ss = ed[1];
            adj[ff].push_back(ss);
            adj[ss].push_back(ff);
        }
        vector<long long> ans;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                long long res = dfs(adj,i,visited);
                ans.push_back(res);
            }
        }

        long long finalans = 0;

        for(auto i:ans){
            finalans+= (1ll*i* (n-i));
        }
        return finalans>>1;

    }
};