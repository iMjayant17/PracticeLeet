class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        if(nums[s]<nums[e]) return nums[s];

        while(s+1<e){
            int mid = e - (e-s)/2;
            if(nums[mid]<nums[s]){
                if(mid-1>=0 && nums[mid-1]>nums[mid]){
                    return nums[mid];
                }
                else{
                    e = mid;
                }
            }
            else{
                if(mid-1>=0 && nums[mid-1]>nums[mid]){
                    return nums[mid];
                }
                else{
                    s = mid;
                }
            }
        }
        return min(nums[s],nums[e]);
    }
};