class Solution {
public:
set<vector<int>> ans;
    void solve(vector<int> &nums ,int idx){
        if(idx==nums.size()){
        ans.insert(nums);
            return;
        }
            solve(nums,idx+1);

        for(int i = idx+1;i<nums.size();i++){
            if(nums[idx]!=nums[i]){
                swap(nums[i],nums[idx]);
            solve(nums,idx+1);
            swap(nums[i],nums[idx]);
            }
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = 0;j<nums.size();j++){
        //         swap(nums[i],nums[j]);
        //         ans
        //     }
        // }
        vector<vector<int>> res = vector<vector<int>>(ans.begin(),ans.end());
        
        return res;
    }
};