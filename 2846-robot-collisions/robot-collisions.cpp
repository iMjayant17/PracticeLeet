class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h,
                                      string d) {
        vector<pair<int, int>> left, right;
        vector<tuple<int, int, char>> arr;
        for (int i = 0; i < p.size(); i++) {
            arr.push_back({p[i], h[i], d[i]});
        }
        sort(arr.begin(), arr.end());
        map<int, int> t;
        for (int i = 0; i < p.size(); i++) {

            auto [a, b, c] = arr[i];
            t[a] = i;
            if (c == 'L') {
                while (right.size() > 0 && right.back().second < b) {
                    right.pop_back();
                    b--;
                }
                if (right.size() == 0) {
                    left.push_back({i, b});
                }
                if (right.size() > 0 && right.back().second >= b) {
                    if (right.back().second == b)
                        right.pop_back();
                    else
                        right.back().second--;
                }
            } else {
                right.push_back({i, b});
            }
        }
        map<int, int> m;
        for (auto i : left) {
            m[i.first] = i.second;
        }
        for (auto i : right) {
            m[i.first] = i.second;
        }
        vector<int> ans;
        for (int i = 0; i < p.size(); i++) {
            if (m.find(t[p[i]]) != m.end())
                ans.push_back(m[t[p[i]]]);
        }
        return ans;
    }
};