class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto i: strs){
            string j = i;
            sort(j.begin(),j.end());
            m[j].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i: m){
            ans.push_back(i.second);
        }

        return ans;
    }
};