class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int arr[1000005]={0};
        for(auto it : intervals){
            int s = it[0];
            int e = it[1];
            arr[s]++;
            arr[e+1]--;
        }
        int ans = 0;
        for(int i = 1;i<1000005;i++){
            arr[i]+=arr[i-1];
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};