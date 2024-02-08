class Solution {
public:
map<char,string> m;
vector<string> ans;
string curr;
    void solve(string s,int idx){
        if(curr.length()==s.length() && s.length()>0){
            ans.push_back(curr);
            return;
        }
        string word = m[s[idx]];
        for(int i = 0;i<word.length();i++){
            curr.push_back(word[i]);
            solve(s,idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        // curr = "";
        solve(digits,0);
        return ans;

    }
};