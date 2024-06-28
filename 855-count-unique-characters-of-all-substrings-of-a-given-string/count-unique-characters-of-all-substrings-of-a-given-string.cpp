class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), mod = 1e9+7;
        vector<int> lastOccurrence(26,-1), secondLastOccurrence(26, -1);
        long int res = 0;
        for(int i = 0; i < n; ++i){
            int c = s[i] - 'A';
            res += (i-lastOccurrence[c])*(lastOccurrence[c]-secondLastOccurrence[c]);
            res %= mod;
            secondLastOccurrence[c] = lastOccurrence[c], lastOccurrence[c] = i;
        }
        for(int i = 0; i < 26; ++i){
            res += (n-lastOccurrence[i])*(lastOccurrence[i]-secondLastOccurrence[i]);
            res %= mod;
        }
        return res;
    }
};