class Solution {
public:
    set<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& arr, int target,int idx){

        if(target==0){
            ans.insert(curr);
            return;
        }

        for(int i = idx;i<arr.size();i++ ){
            if(i>idx && arr[i]==arr[i-1])continue; // this is the catch...!!
            if(arr[i]<=target){
            curr.push_back(arr[i]);
            solve(arr,target-arr[i],i+1);
            curr.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(),arr.end());
    solve(arr,target,0);
    vector<vector<int>> res;
    for(auto i:ans){
        res.push_back(i);
    }
    return res;    
    }
};