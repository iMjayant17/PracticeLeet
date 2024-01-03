class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> kmp(n, 0);
        // kmp[0] = 0;
        int k = 0;
        for (int i = 1; i < n; i++) {

            while (k > 0 && s[k] != s[i]) {
                k = kmp[k - 1];
            }
            if (s[i] == s[k]) {
                k++;
            }
            kmp[i] = k;
        }
        string ans = "";
        for (int i = 0; i < kmp[n - 1]; i++)
            ans.push_back(s[i]);

        // for (auto i : kmp) {
        //     cout << i << " ";
        // }
        // cout << endl;
        return ans;
    }
};