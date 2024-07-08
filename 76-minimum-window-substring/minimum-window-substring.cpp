class Solution {
public:
    map<char,int> tt;
    bool check(map<char,int> &m){
        for(auto i:tt){
            if(m.find(i.first)==m.end()) return false;
            else{
                if(m[i.first]<i.second) return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int i = 0;
        int e =0;
        for(auto i:t){
            tt[i]++;
        }
        map<char,int> m;
        int ans = INT_MAX;
        int st = 0;
        while(e<s.length()){
            
            m[s[e]]++;
            e++;
            
            while(i<s.length() && check(m)){
                if(e-i < ans){
                    ans = e-i;
                    st = i;
                }
                m[s[i]]--;
                i++;
            }
            
        }

        if(ans == INT_MAX) return "";
        return s.substr(st,ans);

    }
};