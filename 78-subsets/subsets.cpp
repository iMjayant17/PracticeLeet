class Solution {
public:

    void subs(vector<int>& nums,int i,vector<vector<int>> &ans,vector<int> storing){
        // base case
        if(i>nums.size()-1){
            ans.push_back(storing);
            return;
        }
        // exclude
        subs(nums,i+1,ans,storing);
        storing.push_back(nums[i]);
        subs(nums,i+1,ans,storing);
        storing.pop_back();

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> storing;
        subs(nums,0,ans,storing);
        return ans;
    }
};