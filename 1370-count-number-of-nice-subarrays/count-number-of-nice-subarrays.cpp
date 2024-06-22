class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i:nums){
            if(i&1) i = 1;
            else i = 0;
        }

        for(int i = 1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        map<int,int> m;
        int ans = 0;
        m[0]++;
        for(auto i:nums){
            ans+= m[i-k];
            m[i]++;    
        }
        return ans;
    }
};