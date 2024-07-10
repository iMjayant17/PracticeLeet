class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& t) {
        vector<int> a ={0,0,0};
        for(int i = 0;i<arr.size();i++){
            if(arr[i][0]<=t[0] && arr[i][1]<=t[1] && arr[i][2]<=t[2]){
                a[0] = max(a[0],arr[i][0]);
                a[1] = max(a[1],arr[i][1]);
                a[2] = max(a[2],arr[i][2]);
            }
        }
        return a==t;
    }
};