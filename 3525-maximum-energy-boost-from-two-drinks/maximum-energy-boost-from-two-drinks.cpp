class Solution {
public:
    long long maxEnergyBoost(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        long long dpA[n],dpB[n];

        dpA[0] = arr[0];
        dpA[1] = arr[0] + arr[1];
        dpB[0] = brr[0];
        dpB[1] = brr[0] + brr[1];

        for(int i = 2;i<n;i++){
            dpA[i] = max(dpA[i-1],dpB[i-2]) + arr[i];
            dpB[i] = max(dpB[i-1],dpA[i-2]) + brr[i];
        }
        return max(dpA[n-1],dpB[n-1]);
    }
};