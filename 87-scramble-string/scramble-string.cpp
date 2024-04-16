class Solution {
public:
map<string,bool> m;
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        string key = s1+'#'+s2;
        if(m.find(key)!=m.end()) return m[key];
        string x = s1;
        string y = s2;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (x != y)
            return m[key] = false;

        int len = s1.length();
        for (int i = 1; i <= len - 1; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return m[key] = true;
            }

            if (isScramble(s1.substr(0, i), s2.substr(len - i)) &&
                isScramble(s1.substr(i), s2.substr(0, len - i)))
                return m[key] = true;
        }

        return m[key] = false;
    }
};