class Solution {
public:
    int hIndex(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();i++){
            if(arr[i]>=i+1){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};