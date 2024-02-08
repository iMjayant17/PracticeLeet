class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool checkPal(string s,int i,int e){
        while(i<e){
            if(s[i]!=s[e]) return false;
            i++;
            e--;
        }
        return true;
    }
    void solve(string s,int idx){
        if(idx>=s.length()){
            ans.push_back(curr);
            return;
        }

        for(int i = idx;i<s.length();i++){
            if(checkPal(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1);
                curr.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};