class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++){
            if(ans.size()==0){
                ans.push_back(arr[i]);
                continue;
            }
            if(ans.back()[1]<=arr[i][0]){
                ans.push_back(arr[i]);
            }
            else{
                if(ans.back()[1]>= arr[i][1]){
                    ans.pop_back();
                    ans.push_back(arr[i]);
                }
            }
        }
        return arr.size() - ans.size();
    }
};