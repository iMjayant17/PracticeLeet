/*
                           with DFS
class Solution {
public:

    void dfs(int idx,vector<vector<int>>& stones,vector<bool> &visited){
        visited[idx]  =true;
        int r = stones[idx][0];
        int c = stones[idx][1];
        for(int i = 0;i<stones.size();i++){
            if(visited[i]==true) continue;
            if(stones[i][0] == r || stones[i][1]==c){
                dfs(i,stones,visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,false);

        int ans = 0;
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                dfs(i,stones,visited);
                ans++;
            }
        }

        return n - ans;
    }
};

*/


// with DSU
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
        else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n = 100005;
        rank.resize(n); 
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        } 


        for(auto st:stones){
            Union(st[0], st[1]+10008);
        }
        set<int> st;
        for(auto i:stones){
            int a = find(i[0]);
            // int b = find(i[1]+10008);
            st.insert(a);
            // st.insert(b);
        }

        return stones.size() - st.size();
    }
};