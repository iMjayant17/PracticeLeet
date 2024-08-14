class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc = 1,dec = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<0){
                dec = max(dec,inc+1);
            }
            else if(nums[i]-nums[i-1]>0){
                inc = max(inc,dec+1);
            }
        }
        return max(inc,dec);
    }
};