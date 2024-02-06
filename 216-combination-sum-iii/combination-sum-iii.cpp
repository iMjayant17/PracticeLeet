class Solution {
public:
vector<vector<int>> ans;
vector<int> curr;
void solve(vector<int> &arr,int sizee,int target,int idx){
    if(sizee==0 && target==0){
        set<int> s;
        for(auto i : curr){
            s.insert(i);
        }
        if(s.size()==curr.size() && is_sorted(curr.begin(),curr.end())) ans.push_back(curr);

        return;
    }
    if(sizee<0 || target<0){
        return;
    }
    for(int i = idx;i<arr.size();i++){
        curr.push_back(arr[i]);
        solve(arr,sizee-1,target-arr[i],idx+1);
        curr.pop_back();
        // solve(arr,sizee,target,idx+1);
    }
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        solve(arr,k,n,0);
       return ans; 
    }
};