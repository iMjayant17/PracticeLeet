class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int , vector<int>> adj;
        int n = graph.size();
        vector<int> indegree(n),ans;
        for(int i = 0;i<graph.size();i++){
            for(auto j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> Q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }
        // vector<boo>
        while(Q.size()>0){
            int node = Q.front();
            Q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]<=0) Q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};