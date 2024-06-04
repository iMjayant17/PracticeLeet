class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            while(nums[i] !=i-1){
                if(nums[i]==nums[nums[i]]) return nums[i];
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    
    }
};