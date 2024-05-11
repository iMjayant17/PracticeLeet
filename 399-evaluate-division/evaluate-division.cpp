class Solution {
public:

    void dfs(string src,string des,unordered_map<string,vector<pair<string,double>>> &adj
    ,double prod,double &ans,unordered_set<string>& visited){

        if(visited.find(src)!=visited.end()){
            return;
        }
        visited.insert(src);
        if(src==des){
            ans = prod;
            return;
        }

        for(auto i:adj[src]){
            string newSrc = i.first;
            double newVal = i.second;
            dfs(newSrc,des,adj,prod*newVal,ans,visited);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i = 0;i<equations.size();i++){
            string src = equations[i][0];
            string des = equations[i][1];
            double val = values[i];
            adj[src].push_back({des,val});
            adj[des].push_back({src,1.0/val});
        }

        vector<double> result;

        for(auto q:queries){
            string src = q[0];
            string des = q[1];
            double ans = -1.0;
            double prod = 1.0;
            unordered_set<string> visited;
            if(adj.find(src)!=adj.end()){
                dfs(src,des,adj,prod,ans,visited);
            }
            result.push_back(ans);
        }

        return result;
    }
};