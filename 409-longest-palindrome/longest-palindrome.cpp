class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        bool odd = false;
        int ans = 0;
        for(auto i:m){
            ans += (i.second/2);
            ans += (i.second/2);
            if(i.second & 1 ) odd = true;
        }
        if(odd) ans++;
        return ans;
    }
};