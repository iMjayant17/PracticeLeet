class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;

    void solve(int k,int idx,int n){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i = idx;i<=n;i++){
            curr.push_back(i);
            solve(k,i+1,n);
            curr.pop_back();
        }
        

    }
    vector<vector<int>> combine(int n, int k) {
        solve(k,1,n);
        return ans;
    }
};