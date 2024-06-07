class Solution {
public:
    string replaceWords(vector<string>& dic, string s) {
        map<string,bool> m;
        for(auto i:dic){
            m[i] = true;
        }
    string ans= "";
        for(int i= 0;i<s.length();i++){
            string temp = "";
            string val = "";
            int j = i;
            while(j<s.length() && s[j]!=' '){
                temp.push_back(s[j]);
                if(val=="" && m.find(temp)!=m.end()){
                    val = temp;
                }
                j++;
            }
            i = j;
            if(val!=""){
                ans += val;
                ans.push_back(' ');
            }
            else{
                ans+=temp;
                ans.push_back(' ');

            }
            

        }
    ans.pop_back();
        return ans;
    }
};