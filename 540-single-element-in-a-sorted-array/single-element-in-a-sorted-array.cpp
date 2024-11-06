class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        if(e==0) return nums[e];
        if(nums[s]!=nums[s+1]) return nums[s];
        while(s+1<e){
            int mid = e - (e-s)/2;

            if(mid&1){
                if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){
                    return nums[mid];
                }
                else if(nums[mid]==nums[mid+1]){
                    e = mid; 
                }
                else{
                    s = mid;
                }
            }
            else{
                if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){
                    return nums[mid];
                }
                else if(nums[mid]==nums[mid+1]){
                    s = mid; 
                }
                else{
                    e = mid;
                }
            }
        }

        if(nums[s]!=nums[s-1] && nums[s]!= nums[s+1]){
                    return nums[s];
        }
        return nums[e];
    }
};