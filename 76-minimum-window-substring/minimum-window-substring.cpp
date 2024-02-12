class Solution {
public:
bool check(unordered_map<char,int> &s,unordered_map<char,int> &t){
    for(auto i:t){
        if(s[i.first]<i.second) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        unordered_map<char,int> mt,ms;
        for(auto i:t){
            mt[i]++;
        }
        int i = 0,j = 0;
        int st = 0,e = INT_MAX;
        while(j<s.length()){
            ms[s[j]]++;
            j++;
            while(check(ms,mt) && i<j){
                if(e-st > j-i){
                    e = j;
                    st = i;
                }
                ms[s[i]]--;
                i++;
            }
        }
        string ans = "";
        if(e== INT_MAX) return ans;
        for(int i = st;i<e;i++){
            ans.push_back(s[i]);
        }
        // cout<<st<<" "<<e<<endl;
        return ans;

    }
};