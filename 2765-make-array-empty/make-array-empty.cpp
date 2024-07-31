class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        map<long long, long long> m;
        for (long long i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        long long n = nums.size();
        long long cnt = 0, ans = 0;
        long long last = -1;
        for (auto val : temp) {
            long long idx = m[val];
            if (idx > last) {
                cnt++;
                last = idx;
            } else {
                ans += n;
                n -= cnt;
                cnt = 1;
                last = idx;
            }
        }
        return ans += n;
    }
};