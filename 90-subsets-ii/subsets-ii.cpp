class Solution {
public:
    set<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int> &nums,int idx){

        if(idx==nums.size()){
               sort(curr.begin(),curr.end());
                ans.insert(curr);
                return;
            }



            curr.push_back(nums[idx]);
            solve(nums,idx+1);
            curr.pop_back();
            solve(nums,idx+1);
        
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