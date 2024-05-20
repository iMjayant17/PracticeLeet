class Solution {
public:
    
    vector<int> grp;
    vector<int> parentSum;
    vector<int> parent;
    void dfs(vector<vector<int>> &adj,int node,int depth = 0,int par = -1){
        parent[node] = par;
        parentSum[0]+=depth;
        int cnt = 0;
        for(auto child:adj[node]){
            if(child==par) continue;
             dfs(adj,child,depth+1,node);
            
        grp[node] += grp[child];
        }
        grp[node]++;
    }

    void solve(vector<vector<int>> &adj,int node,int par = -1){
        
        
        if(node!=0){
            parentSum[node] = parentSum[par] - (2*grp[node]) + grp.size(); 
        }
        cout<<node<<endl;
        for(auto child:adj[node]){
            // cout<<child<<" child"<<endl;
            if(child==par) continue;
            // cout<<"called"<<endl;
             solve(adj,child,node);
        }
        
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        grp.resize(n,0);
        parentSum.resize(n,0);
        parent.resize(n,0);
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(adj,0);
        // for(auto i:grp){cout<<i<<" ";
        // }
        // cout<<endl; 
        // for(auto i:parent){cout<<i<<" ";
        // }
        // cout<<endl; 
        // for(auto i:parentSum){cout<<i<<" ";
        // }
        // cout<<endl; 
        // for(int i = 1;i<n;i++){
        //     parentSum[i] = parentSum[parent[i]] -(2*grp[i]) + grp.size();
        // }

        solve(adj,0);
        return parentSum;
    }
};