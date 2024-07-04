class Solution {
public:
    bool isValid(string s) {
        string j = "*";
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                j.push_back(s[i]);
            }
            else{
                if(j.back()=='(' && s[i]==')'){
                    j.pop_back();
                }
                else if(j.back()=='{' && s[i]=='}'){
                    j.pop_back();
                }
                else if(j.back()=='[' && s[i]==']'){
                    j.pop_back();
                }
                else return false;
            }
        }
        return j.length()==1;
    }
};