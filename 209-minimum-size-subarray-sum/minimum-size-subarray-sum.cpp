class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        // start and end pointer
        int i = 0;
        int e = 1;
        int sum = nums[0];

        while(e<n){

            while(sum<target && e<n){
                sum+=nums[e];
                e++;
            }
            
            while(sum>=target){

                ans = min(ans,e-i+1);
                sum-=nums[i];
                i++;
            }
            
            if(e>n-1) break;


        }
        
        if(sum>=target){
            ans = min(ans,e-i+1);
        }


        if(ans == INT_MAX) return 0;
        return ans-1; 
    }
};