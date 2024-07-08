class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx ,vector<int> &nums,vector<int> &temp){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
            temp.push_back(nums[idx]);
            solve(idx+1,nums,temp);
            temp.pop_back();
            while(idx<nums.size()-1 && nums[idx]==nums[idx+1]){
                idx++;
            }
            solve(idx+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,nums,temp);
        return ans;
    }
};