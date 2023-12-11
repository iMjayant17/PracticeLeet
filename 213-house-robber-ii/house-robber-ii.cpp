class Solution {
public:
int robb(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        if(n==1) return ans[0];
        ans[1] = max(nums[1],nums[0]);
        if(n==2) return ans[1];
        for(int i = 2;i<n;i++){
            ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
        }

        return ans[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        int n = nums.size();
        if(n==1) return nums[0];
    
        for(int i = 1;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        for(int i = 0;i<nums.size()-1;i++){
            nums2.push_back(nums[i]);
        }

        return max(robb(nums1),robb(nums2));
    }
};