class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long long n = nums.size();
        long long s = 0;
        long long e = n - 1;
        while (s < e) {
            long long mid = (s + e) / 2;
            long long a = mid - 1 >= 0 ? nums[mid - 1] : LLONG_MIN;
            long long b = nums[mid];
            long long c = mid + 1 <= n - 1 ? nums[mid + 1] : LLONG_MIN;
            if (a < b && b > c) {
                return mid;
            } else if (a > b) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};