class Solution {
public:
    vector<int> ans;

    vector<int> dfs(vector<vector<int>>& adj,int node ,string &label,int par = -1){

        // string str = "";
        vector<int> temp(26,0);
        
        for(auto child:adj[node]){
            if(child==par) continue;
            vector<int> t = dfs(adj,child,label,node);
            for(int i = 0;i<26;i++){
                temp[i]+=t[i];
            }
            
        }
        
        temp[label[node]-'a']++;
        ans[node] += temp[label[node]-'a'];
        return temp ;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> temp = dfs(adj,0,labels);

        return ans;

    }
};