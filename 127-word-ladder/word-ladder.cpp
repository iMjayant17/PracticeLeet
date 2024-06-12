class Solution {
public:
    bool check(string s, string j) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != j[i])
                cnt++;
        }

        if (cnt <= 1)
            return true;
        return false;
    }

    int ladderLength(string start, string last, vector<string>& bank) {
        queue<string> Q;
        int n = bank.size();
        // multiset<string> bank(bank.begin(), bank.end());
        Q.push(start);
        unordered_map<int,bool> m;
        int cnt = 0;
        while (Q.size() > 0) {
            int sz = Q.size();
            while (sz--) {
                string s = Q.front();
                Q.pop();
                if (s == last)
                    return cnt + 1;

                for (int i = 0;i<bank.size();i++) {
                    if(m[i]==true) continue;
                    if (check(bank[i], s)) {
                        Q.push(bank[i]);
                        m[i] = true;
                    }
                }
            }
            cnt++;
        }

        return 0;
    }
};