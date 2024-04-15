class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto i:p){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0;i<n;i++ ){
            if(indegree[i]==0) q.push(i);
        }

        while(q.size()>0){
            int child = q.front();
            q.pop();
            ans.push_back(child);
            for(auto x:adj[child]){
                if(indegree[x]<=0) continue;
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=n) return {};
        return ans;
    }
};