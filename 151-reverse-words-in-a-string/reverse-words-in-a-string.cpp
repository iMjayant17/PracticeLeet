class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string temp="";
        string ans="";
        for( int i = 0;i<s.length();i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else{
                if(temp!=""){
                    vs.push_back(temp);
                    temp = "";
                }
            }
        }
        if(temp!=""){
                    vs.push_back(temp);
                    temp = "";
        }
        reverse(vs.begin(),vs.end());
        ans = ans + vs[0];
        for(int i = 1;i<vs.size();i++){
            ans = ans + " "+vs[i];
        }
        return ans;
    }
};