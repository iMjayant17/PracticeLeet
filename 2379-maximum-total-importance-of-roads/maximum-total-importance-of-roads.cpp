class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> temp;
        for(auto i:adj){
            temp.push_back(i.size());
        }
        sort(temp.begin(),temp.end());
        long long ans = 0;
        for(int i = 0;i<temp.size();i++){
            ans+= 1ll*(i+1)*temp[i];
        }
        return ans;
    }
};