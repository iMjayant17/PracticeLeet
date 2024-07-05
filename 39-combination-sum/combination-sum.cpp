class Solution {
public:

    vector<vector<int>> res;

    void dfs(vector<int>& arr,int idx, int sum,vector<int> temp={}){
        if(idx>=arr.size() || sum<0) return;
        if(sum==0){
            res.push_back(temp);
            return;
        }

        temp.push_back(arr[idx]);
        dfs(arr,idx,sum-arr[idx],temp);
        temp.pop_back();
        dfs(arr,idx+1,sum,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        return res;
    }
};