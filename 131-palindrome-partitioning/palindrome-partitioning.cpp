class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &k){
        string temp = k;
        reverse(temp.begin(),temp.end());
        return temp==k;
    }
    void solve(int idx,string &s , vector<string> &temp){
        if(idx>=s.length()){
            ans.push_back(temp);
            return;
        }

        string k = "";
        for(int i = idx;i<s.length();i++){
            k.push_back(s[i]);
            if(isPalindrome(k)){
                temp.push_back(k);
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0,s,temp);
        return ans;
    }
};