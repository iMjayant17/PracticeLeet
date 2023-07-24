class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,set<char>> m;
        map<char,set<char>> p;
        for(int i = 0;i<s.length();i++){
            m[s[i]].insert(t[i]);
            p[t[i]].insert(s[i]);
        }

        for(auto i : m){
            if(i.second.size()>1){
                return false;
            }
        }

        for(auto i : p){
            if(i.second.size()>1){
                return false;
            }
        }
        return true;
    }
};