class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,int> m;
        int i = 0;
        int e = 0;
        while(e<s.length()){
            while(m[s[e]]>0){
                m[s[i]]--;
                i++;
            }
            ans = max(ans,e-i+1);
            m[s[e]]++;
            e++;
        }
        return ans;
    }
};