class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long val = 0;
        for(auto i:nums){
            val = val^i;
        }

        long long val2 = val & (~(val-1));
        long long ans1 = 0;
        for(auto i:nums){
            if(val2&i){
                ans1 = ans1^i;
            }
        }
        return {(int)ans1,(int)(ans1^val)};
    }
};