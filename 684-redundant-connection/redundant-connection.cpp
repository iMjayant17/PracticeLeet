class Solution {
public:

    int find(int i,vector<int> &parent){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i],parent);
    }

    void Union(int x,int y,vector<int> &parent,vector<int> &rank){
        int x_par = find(x,parent);
        int y_par = find(y,parent);

        if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else if(rank[y_par]<rank[x_par]){
            parent[y_par] = x_par;
        }
        else {
            parent[x_par] = y_par;
            rank[y_par]++;
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans,parent(n+1,0),rank(n+1);
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
        }

        for(auto ed:edges){
            int ff = ed[0];
            int ss = ed[1];

            if(find(ff,parent) == find(ss,parent)){
                ans = {ff,ss};
            }
            Union(ff,ss,parent,rank);
        }

        return ans;

    }
};