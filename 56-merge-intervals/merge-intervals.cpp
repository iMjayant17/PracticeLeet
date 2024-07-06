class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1;i<arr.size();i++){
            vector<int> temp = ans.back();
            ans.pop_back();
            if(arr[i][0]<=temp[1]) ans.push_back({temp[0],max(arr[i][1],temp[1])});
            else{
                ans.push_back(temp);
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};