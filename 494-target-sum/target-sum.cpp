class Solution {
public:

    int solve(vector<int>& nums , int idx,int sum){
        if(idx>=nums.size()){
            if(sum==0) return 1;
            return 0;
        }

        int i= 0,e = 0;
        if(sum >= nums[idx]){
            i = solve(nums,idx+1,sum-nums[idx]);
        }
        e = 0 + solve(nums,idx+1,sum);
        return i+e;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int k = accumulate(nums.begin(),nums.end(),0) + target;
        if(k&1) return 0;
        k = k>>1;
        cout<<k<<endl;
        return  solve(nums,0,k);

    }
};