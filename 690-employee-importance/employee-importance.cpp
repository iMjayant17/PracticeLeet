/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,bool> visited;
    int dfs(unordered_map<int,pair<int,vector<int>>> &adj, int id){
        if(visited[id]==true){
            return 0;
        }
        visited[id] = true;
        int ans = adj[id].first;
        for(auto i : adj[id].second){
            ans+= dfs(adj,i);
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int,pair<int,vector<int>>> adj;

        for(auto i :employees){
            adj[i->id] ={i->importance , i->subordinates};
        }
        return dfs(adj,id);
    }
};