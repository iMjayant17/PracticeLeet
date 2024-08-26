class TreeAncestor {
public:
    int par[50005];
    int level[50005];
    int nthAnce[50005][20];
    vector<vector<int>>adj;

    void dfs(int node,int p = 0,int l = 1){
        par[node] = p;
        level[node] = l;
        nthAnce[node][0] = p;
        for(int i=1;i<18;i++){
            nthAnce[node][i] = nthAnce[nthAnce[node][i-1]][i-1];
        } 
        for(auto child:adj[node]){
            if(child==p) continue;
            dfs(child,node,l+1);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        adj.resize(n+5);
        for(int i = 1;i<parent.size();i++){
            adj[i+1].push_back(parent[i]+1);
            adj[parent[i]+1].push_back(i+1);
        }
        dfs(1);
    }
    
    int getKthAncestor(int node, int k) {
        node++;
        int cnt = 0;
        while(k){
            if(k&1){
                node = nthAnce[node][cnt]; 
            }
            cnt++;
            k=k>>1;
        }
        return node-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */