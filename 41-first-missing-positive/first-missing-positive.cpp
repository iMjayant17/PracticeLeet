class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool check = true;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                check = false;
            }
        }
        if(check) return 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]> nums.size() || nums[i]<=0) nums[i] = 1;
        }
        for(int i = 0;i<nums.size();i++){
            int val = abs(nums[i]) - 1;
            if(nums[val]>0) nums[val] = (-1) * nums[val];
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return nums.size()+1;
    }
};