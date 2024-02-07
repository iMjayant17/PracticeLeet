class Solution {
public:
    set<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int> &nums,int idx){

            ans.insert(curr);


        for(int i = idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        solve(nums,0);
        for(auto i : ans){
            res.push_back(i);
        }
        return res;
    }
};