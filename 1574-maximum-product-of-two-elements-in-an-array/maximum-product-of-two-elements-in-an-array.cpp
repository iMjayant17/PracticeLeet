class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int val1 = (nums[n-1]-1)*(nums[n-2]-1);
        int val12 = (nums[1]-1)*(nums[0]-1);

        return max(val1,val12);
    }
};