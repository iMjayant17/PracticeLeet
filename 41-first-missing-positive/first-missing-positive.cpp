class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int j = 1;
        for(auto i:nums){
            if(i<j) continue;
            else if(i==j){
                j++;
            }
            else{
                return j;
            }
        }
        return j;
    }
};