class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 1;
        for(int diff = -500 ;diff<=500;diff++){
            unordered_map<int,int> m;
            m[nums[0]] = 1;
            for(int i = 1;i<nums.size();i++){
                if(m.find(nums[i]+diff)==m.end()){
                    m[nums[i]] = 1;
                }
                else{
                    m[nums[i]] = max(m[nums[i]],m[nums[i]+diff]+1);
                }
                ans = max(ans,m[nums[i]]);
            }
        }
        return ans;
    }
};