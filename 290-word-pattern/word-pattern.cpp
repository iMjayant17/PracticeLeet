class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp = "";
        for(int i= 0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        v.push_back(temp);
        if(v.size()!=pattern.length()) return false;
        for(auto i:v){
            cout<<i<<endl;
        }
        map<char,set<string>> m;
        map<string,set<char>> p;
        for(int i = 0;i<pattern.length();i++){
            
            m[pattern[i]].insert(v[i]);
            p[v[i]].insert(pattern[i]);
        }

        for(auto i:m){
            if(i.second.size()>1){
                return false;
            }
        }

        for(auto i:p){
            if(i.second.size()>1){
                return false;
            }
        }
        return true;
    }
};