class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long double ans1= INT_MIN;
        long double ans2 = INT_MIN;
        long long n = nums.size();
        long double prod = 1;
        for(long long i = 0;i<n;i++){
            prod = prod*nums[i];
            ans1 = max(ans1,prod);

            if(prod==0) prod = 1;
        }

        prod = 1;

        for(long long i = n-1;i>=0;i--){
            prod = 1ll*prod*nums[i];
            ans2 = max(ans2,prod);

            if(prod==0) prod = 1;
        }

        return max(ans1,ans2);
    }
};