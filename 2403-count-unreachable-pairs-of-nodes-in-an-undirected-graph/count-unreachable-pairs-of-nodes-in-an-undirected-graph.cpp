class Solution {
public:
    long long dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
        if (visited[node]) {
            return 0;
        }
        visited[node] = true;
        long long ans = 0;
        for (auto child : adj[node]) {
            long long temp = dfs(adj, child, visited);
            ans += temp;
        }
        return 1 + ans;
    }
    /* Now by DSU*/

    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_par = find(x, parent);
        int y_par = find(y, parent);

        if (rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        } else if (rank[y_par] < rank[x_par]) {
            parent[y_par] = x_par;
        } else {
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        //     vector<vector<int>> adj(n);
        //     vector<bool> visited(n,false);

        //     for(auto ed:edges){
        //         int ff = ed[0];
        //         int ss = ed[1];
        //         adj[ff].push_back(ss);
        //         adj[ss].push_back(ff);
        //     }
        //     vector<long long> ans;
        //     for(int i = 0;i<n;i++){
        //         if(!visited[i]){
        //             long long res = dfs(adj,i,visited);
        //             ans.push_back(res);
        //         }
        //     }

        //     long long finalans = 0;

        //     for(auto i:ans){
        //         finalans+= (1ll*i* (n-i));
        //     }
        //     return finalans>>1;

        // }
        vector<int> parent(n, 0), rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto ed : edges) {
            Union(ed[0], ed[1], parent, rank);
        }

        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[find(i, parent)]++;
        }

        long long finalans = 0;

        for (auto i : m) {
            finalans += (1ll * i.second * (n - i.second));
        }
        return finalans >> 1;
    }
};