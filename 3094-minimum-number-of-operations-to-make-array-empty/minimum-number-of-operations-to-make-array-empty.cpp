class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int current = 0, nextu = 1;
        int ans = 0, count = 1;

        while (nextu <= nums.size()) {
            if (nextu < nums.size() && nums[current] == nums[nextu]) {
                count++;
                nextu++;
            } else if (nextu == nums.size() || nums[current] != nums[nextu]) {
                if (count == 1) {
                    return -1;
                }

                ans += count / 3;
                if (count % 3 > 0) {
                    ans += 1;
                }

                current = nextu;
                nextu++;
                count = 1;
            }
        }

        return ans;
    }
};