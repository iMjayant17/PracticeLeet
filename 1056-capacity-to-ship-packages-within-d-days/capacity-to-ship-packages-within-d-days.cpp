class Solution {
public:

    bool check(vector<int>& arr, int k,int mid){

        int sum = 0;
        int val = 0;
        for(auto i:arr){
            if(i>mid) return false;
            if(sum+i>mid){
                val++;
                sum = 0;
            }
            sum+=i;
        }

        if(sum>0) val++;
        return val<=k;
    }

    int shipWithinDays(vector<int>& arr, int k) {
        int s = 0;
        int e = accumulate(arr.begin(),arr.end(),0ll);

        while(s+1<e){
            int mid = e - (e-s)/2;

            if(check(arr,k,mid)){
                e = mid;
            }
            else{
                s =mid;
            }
        }

        return e;
    }
};