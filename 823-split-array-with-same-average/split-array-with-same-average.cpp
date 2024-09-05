class Solution {
public:
    map<string, int> mp;

    bool helper(vector<int>& nums, int i, int n, int sum, int n1) {
        if (n1 == 0)
            return sum == 0;
        if (i == n)
            return false;
        string key = to_string(i) + "#" + to_string(n1) + "#" + to_string(sum);
        if (mp.count(key))
            return mp[key];

        if (nums[i] <= sum) {
            return mp[key] = helper(nums, i + 1, n, sum - nums[i], n1 - 1) ||
                             helper(nums, i + 1, n, sum, n1);
        } else
            return mp[key] = helper(nums, i + 1, n, sum, n1);
    }

    bool splitArraySameAverage(vector<int>& nums) {
        /*
        Let's try to see what happens when an answer exists.
        Assume we split the array A into B and C so that avg(B) == avg(C).
        It follows that avg(B) == avg(C) == avg(A)
        So we only need to find a proper subset B such that avg(B) == avg(A) and
        we can just put the remaining elements in C. Now if avg(B)==avg(A), that
        means sum(B) /B.length == sum(A) / N or, sum(B) == sum(A) * B.length / N
        */
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        int n = nums.size();
        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(n + 1, vector<bool>(sum + 1, false)));
        for (int i = 1; i < n; i++) {
            if ((sum * i) % n == 0) {
                int req_sum = (sum * i) / n;
                if (helper(nums, 0, n, req_sum, i))
                    return true;
            }
        }
        return false;
    }
};