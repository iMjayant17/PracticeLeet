class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> m;
        for(int i = 0;i<g.size();i++){
            m[g[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for(auto i: m){
            vector<int> temp;
            for(auto j: i.second){
                temp.push_back(j);
                if(temp.size()%i.first==0){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }

        return ans;

    }
};