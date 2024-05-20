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