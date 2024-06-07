class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int val = -1;
        for(int i= 0;i<nums.size()-1 ;i++){
            if(nums[i]<nums[i+1]){
                val = i;
            }
        }
        if(val==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            int swapped = -1;
            for(int i = 0;i<nums.size();i++){
                if(nums[val]<nums[i]){
                    swapped = i;
                }
            }

            swap(nums[val],nums[swapped]);
            reverse(nums.begin()+val+1,nums.end());
        }
        
    }
};