class Solution {
public:

    bool check(vector<int>& arr, int m,int mid){
        int cnt = 1;
        int  last = arr[0];
        for(int i = 1;i<arr.size();i++){
            if(arr[i]-last>=mid){
                last = arr[i];
                cnt++;
            }
        } 
        return cnt>=m;
    }

    int maxDistance(vector<int>& arr, int m) {
        long long l = 1,r = 1e10;
        sort(arr.begin(),arr.end());

        while(l+1<r){
            long long mid = r - (r-l)/2;

            if(check(arr,m,mid)){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        return l;

    }
};