class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last = nums[0];
        int ans = 0;
        for(auto i:nums){
            cout<<i<<" ";
        }
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=nums[i-1] ){
                ans+= (last+1 - nums[i]);
                nums[i] = last+1;
                last = nums[i];
            }
            else{
                last = nums[i];
            }
        }
        return ans;
    }
};