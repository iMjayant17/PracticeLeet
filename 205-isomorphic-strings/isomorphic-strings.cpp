class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char,set<char>> m;
        // map<char,set<char>> p;
        // for(int i = 0;i<s.length();i++){
        //     m[s[i]].insert(t[i]);
        //     p[t[i]].insert(s[i]);
        // }

        // for(auto i : m){
        //     if(i.second.size()>1){
        //         return false;
        //     }
        // }

        // for(auto i : p){
        //     if(i.second.size()>1){
        //         return false;
        //     }
        // }
        // return true;


        set<char> a[1000];
        set<char> b[1000];
        for(int i = 0;i<s.length();i++){
            a[(int)s[i]].insert(t[i]);
            b[(int)t[i]].insert(s[i]);
        }

        for(int i = 0;i<1000;i++){
            if(a[i].size()>1 || b[i].size()>1){
                return false;
            }
        }

        return true; 
    }
};