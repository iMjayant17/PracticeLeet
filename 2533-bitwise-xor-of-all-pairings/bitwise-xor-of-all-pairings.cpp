class Solution {
public:
int findxor(vector<int>& nums){
    int ans = 0;
    for(auto i:nums){
        ans = ans^i;
    }

    return ans;
}
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans =0;
        if(nums1.size()&1){
            ans = ans^findxor(nums2);
        }

        if(nums2.size()&1){
            ans =ans^findxor(nums1);
        }

        return ans;
    }
};