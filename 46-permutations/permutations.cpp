class Solution {
public:
    set<vector<int>> ans;
    void solve(int ind,int idx,vector<int>&arr){
        if(ind>=arr.size()){
            ans.insert(arr);
            return;
        }

        for(int i = 0;i<arr.size();i++){
            swap(arr[i],arr[ind]);
            solve(ind+1,i,arr);
            swap(arr[i],arr[ind]);;
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,0,nums);
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};