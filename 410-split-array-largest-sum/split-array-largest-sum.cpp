class Solution {
public:

    bool check(vector<int>& nums, int k,int mid){
        int sum = 0;
        int val = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            if(sum+nums[i]>mid){
                val++;
                sum = 0;
            }
            sum+=nums[i];
        }
        if(sum>0) val++;

        return val<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int e = accumulate(nums.begin(),nums.end(),0ll);
        while(s+1<e){
            int mid = e - (e-s)/2;
            if(check(nums,k,mid)){
                e = mid;
            } 
            else{
                s = mid;
            }
        }

        return e;
    }
};