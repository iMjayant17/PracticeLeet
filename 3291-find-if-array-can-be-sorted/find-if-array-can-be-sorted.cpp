class Solution {
public:
    int setBits(int n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vp;
        for (auto i : nums) {
            int sb = setBits(i);
            vp.push_back({i, sb});
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (vp[j].first >= vp[j + 1].first) {
                    if (vp[j].second == vp[j + 1].second) {
                        swap(vp[j], vp[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};