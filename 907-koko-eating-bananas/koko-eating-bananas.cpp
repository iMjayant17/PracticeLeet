class Solution {
public:

    bool check(vector<int>& arr , int h ,int s){
        int cnt = 0;
        for(int i = 0;i<arr.size();i++){
            cnt += (arr[i]+s-1)/s;
        }
        return cnt<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 0;
        int e = 1e9;
        while(s+1<e){
            int mid = e - (e-s)/2;
            if(check(piles,h,mid)){
                e = mid;
            }
            else{
                s = mid;
            }
        }
        return e;
    }
};