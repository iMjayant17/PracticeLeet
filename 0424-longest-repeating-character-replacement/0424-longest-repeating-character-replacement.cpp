class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxfreq = 0;
        int ans = 0;
        map<char,int> m;
        while(i<s.length()){
            m[s[i]]++;
            maxfreq = max(maxfreq,m[s[i]]);
            if(i-j+1-maxfreq>k){
                m[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        } 

        return ans;
    }
};