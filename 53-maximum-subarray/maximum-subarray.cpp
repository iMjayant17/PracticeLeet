class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN; // kadane algorithm
        int sum = 0;
        int s = 0,e = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>ans){
                ans = sum;
                e = i;
            }
            ans = max(ans,sum);
            if(sum<0){
                sum = 0;
                s = i+1;
            } 
        }

        for(int i = s;i<=e;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
};