class Solution {
public:


    bool check(vector<int>& arr, int k,int mid){

        int sum = 0;
        for(auto i:arr){
            sum+= ((i + mid-1)/mid);
        }
        return sum<=k;
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int s = 0;
        int e = 1000005;

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