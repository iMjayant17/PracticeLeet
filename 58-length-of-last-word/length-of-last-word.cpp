class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while( i>=0 && s[i]==' ' ){
            i--;
        }

        int ans = 0;

        while(i>=0 && s[i]!=' ' ){
            i--;
            ans++;
        }

        return ans;
    }
};