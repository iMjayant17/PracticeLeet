class Solution {
public:
    vector<int> parent,rank;

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y){
        int x_par = find(x);
        int y_par = find(y);
        if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else if(rank[y_par]<rank[x_par]){
            parent[y_par] = x_par;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i]  = i;
        }
        vector<vector<int>> adj(n);
        for(auto ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        map<int,vector<int>> m;
        for(int i = 0;i<vals.size();i++){
            m[vals[i]].push_back(i);
        }
    int result = n;
        vector<bool> alive(n,false);
        for(auto x:m){
            for(auto i:x.second){
                alive[i] = true;
            }
            for(auto i:x.second){
                for(auto j:adj[i]){
                    if(alive[j]==false) continue;
                    Union(i,j);
                }
            }
            map<int,int> cnt;
            for(auto i:x.second){
                int p = find(i);
                cnt[p]++;
            }
            for(auto i:cnt){
                result += (i.second * (i.second - 1))/2;
            }
        }

        return result;
    }
};