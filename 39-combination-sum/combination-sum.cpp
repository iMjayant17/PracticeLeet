class Solution {
public:

    set<vector<int>> res;

    void dfs(vector<int>& arr,int idx, int sum,vector<int> temp={}){
        if(idx>=arr.size() || sum<0) return;
        if(sum==0){
            res.insert(temp);
            return;
        }

        temp.push_back(arr[idx]);
        dfs(arr,idx,sum-arr[idx],temp);
        dfs(arr,idx+1,sum-arr[idx],temp);
        temp.pop_back();
        dfs(arr,idx+1,sum,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        vector<vector<int>> ans;
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};