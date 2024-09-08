class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++){
            nums[i] = max(nums[i],nums[i-1]);
        }
        return 1ll*accumulate(nums.begin(),nums.end(),0ll)-nums[nums.size()-1];


    }
};