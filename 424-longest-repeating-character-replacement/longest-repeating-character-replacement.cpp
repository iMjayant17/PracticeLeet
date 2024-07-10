class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        for(int l = 0;l<26;l++){
            int i = 0;
            int j = 0;
            int sum = 0;
            while(j<s.length()){
                if(s[j]-'A' == l) sum++;
                j++;
                while(i<s.length() && j-i-sum>k){
                    if(s[i]-'A' == l) sum--;
                    i++;
                }
                maxi = max(j-i,maxi);
            }
        }
        return maxi;
    }
};