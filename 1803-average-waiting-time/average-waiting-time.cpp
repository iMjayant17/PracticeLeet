class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        double ans=0;
        int st = arr[0][0];
        for(int i = 0;i<arr.size();i++){
            if(st<arr[i][0]) st = arr[i][0]+arr[i][1];
            else st+=arr[i][1];
            ans+= st-arr[i][0];
        }
        return ans/arr.size();
    }
};