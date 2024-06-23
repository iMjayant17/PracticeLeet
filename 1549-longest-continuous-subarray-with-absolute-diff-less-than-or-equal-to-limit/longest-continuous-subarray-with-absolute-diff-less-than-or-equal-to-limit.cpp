class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int i = 0;
        int e = 0;
        int ans = 1; 
        while(e<nums.size()){
            m.insert(nums[e]);
            e++;
            while(*m.rbegin() - *m.begin()>limit){
                m.erase(m.find(nums[i]));
                i++;
            }
            ans = max((int)ans,(int)m.size());
        }
        return ans;
    }
};