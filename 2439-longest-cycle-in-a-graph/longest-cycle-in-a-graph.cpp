class Solution {
public:
    int ans = -1;

    void dfs(int node,vector<int> &edges,vector<bool> &visited,
    vector<bool>& inRec,vector<int> & count,int cnt = 1){
        if(inRec[node]==true){
            ans = max(ans,cnt - count[node]);
            return;
        }
        if(visited[node]==true) return;
        visited[node] = true;
        count[node] = cnt;
        if(edges[node]==-1){
            return;
        }
        else{
            inRec[node] = true;
            dfs(edges[node],edges,visited,inRec,count,cnt+1);
            inRec[node] = false;
        }
    }

    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<bool> visited(n,false);
        vector<bool> inRec(n,false);
        vector<int> count(n,0);
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                dfs(i,edges,visited,inRec,count);
            }
        }
        return ans;
    }
};