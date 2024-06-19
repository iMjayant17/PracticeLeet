class Solution {
public:
    bool check(vector<int>& arr, int mid, int m, int k) {
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                ans+= cnt/k;
                cnt = 0;
            }
        }
        ans+= (cnt/k);
        if(ans>=m) return true;
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if (n < 1ll*m * k)
            return -1;

        int s = 0;
        int e = *max_element(arr.begin(), arr.end());
        while (s + 1 < e) {
            int mid = e - (e - s) / 2;
            if (check(arr, mid, m, k)) {
                e = mid;
            } else {
                s = mid;
            }
        }
        return e;
    }
};