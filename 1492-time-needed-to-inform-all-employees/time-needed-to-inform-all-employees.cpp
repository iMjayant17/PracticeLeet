class Solution {
public:


    int dfs(vector<vector<int>> &adj , int node,vector<int> &t){
        int sum = t[node];
        int maxi = 0;
        for(auto i:adj[node]){
        maxi = max(maxi, dfs(adj,i,t));
        }
        return sum+maxi;
    }

    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& t) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<m.size();i++){
            if(m[i]!= -1) adj[m[i]].push_back(i);
        }
        return dfs(adj , h , t);

    }
};