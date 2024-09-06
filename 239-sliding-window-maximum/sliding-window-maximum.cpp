class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> m;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            m.insert(nums[i]);
            if(m.size()>k) m.erase(m.find(nums[i-k]));
            auto it = m.rbegin();
            if(m.size()==k)ans.push_back(*it);
        }
        return ans;
    }
};