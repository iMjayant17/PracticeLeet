class Solution {
public:
    vector<int> rank,parent;
    
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int a,int b){
        int a_par = find(a);
        int b_par = find(b);

        if(rank[a_par]<rank[b_par]){
            parent[a_par]  = b_par;
        }
        else if(rank[b_par]<rank[a_par]){
            parent[b_par] = a_par;
        }
        else{
            parent[b_par] = a_par;
            rank[a_par]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        vector<int> ans;
        for(auto i:edges){
            int ff = i[0];
            int ss = i[1];

            if(find(ff)==find(ss)){
                ans = {ff,ss};
            }
            else{
                Union(ff,ss);
            }
        }
        return ans;
    }
};