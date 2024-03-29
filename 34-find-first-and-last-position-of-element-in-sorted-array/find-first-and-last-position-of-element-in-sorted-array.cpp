class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(binary_search(nums.begin(),nums.end(),target))
        {
            int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int idx1=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            return {idx,idx1-1};
        }
        return {-1,-1};
        
    }
};