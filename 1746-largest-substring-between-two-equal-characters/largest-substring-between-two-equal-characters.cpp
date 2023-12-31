class Solution {
public:
    int maxLengthBetweenEqualCharacters(string& s) {
        vector<int> alpha(26, -1);
        int n=s.size(), maxLen=-1;
         for (int i = 0; i < n; i++) {
            int idx = s[i]-'a';
            if (alpha[idx]!= -1){
            //    cout<<s[i]<<":"<<maxLen<<endl;
                maxLen= max(maxLen, i-alpha[idx]-1);
            }
            else alpha[idx]=i;
        } 
        return maxLen;    
    }
};