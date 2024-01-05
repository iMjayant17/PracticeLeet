class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        sort(nums.begin(),nums.end());
        set<pair<int,int>> s;
        // m[nums[0]]++;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]-k)!=m.end()){
                s.insert({nums[i]-k,nums[i]});
            }
            m[nums[i]]++;
        }
        return s.size();
    }
};