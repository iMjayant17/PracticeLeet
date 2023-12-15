class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,string> m;
        for(auto i:paths){
            m[i[0]] = i[1];
        }
        string val = paths[0][0]; 
        while(m[val].size()>0){
            val = m[val];
        }
        return val;
    }
};