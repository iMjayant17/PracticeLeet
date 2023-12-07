class Solution {
public:
    bool check(vector<int>& arr, int h,long long check){
        long long time = 0;
        for(long long i = 0;i<arr.size();i++){
            time += (long long)(1ll*arr[i]+1ll*check-1ll)/(long long)check;
        }
        if(time<=h) return true;
        return false;

    }
    int minEatingSpeed(vector<int>& arr, int h) {
        long long s = 1;
        long long e = *max_element(arr.begin(),arr.end());
        long long ans = 0;
        while(s<=e){
            long long mid = (long long)(1ll*s+1ll*e)/2;
            if(check(arr,h,mid)){
                ans = mid; 
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};