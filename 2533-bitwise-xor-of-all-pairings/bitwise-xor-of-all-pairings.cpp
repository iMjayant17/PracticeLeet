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
        int n = nums1.size();
        int m = nums2.size();
        if(n%2==1 && m%2==1){
            ans = findxor(nums1);
            ans = ans^findxor(nums2);
        }
        else if(n%2==0 && m%2==0){
            return ans;
        }
        else{
            if(n%2==0){
                ans = findxor(nums1);
                return ans;
            }
            else{
                return findxor(nums2);
            }
        }

        return ans;
    }
};