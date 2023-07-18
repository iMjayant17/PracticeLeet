class Solution {
public:
    bool isSubsequence(string s, string t) {

        int ans = 0;
        int j = 0;
        for(int i = 0;i<s.length();i++){
            
            for(;j<t.length();j++){
                if(s[i]==t[j]){
                    ans++;
                    j++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
        if(ans==s.length()){
            return true;
        }


        return false;
    }
};