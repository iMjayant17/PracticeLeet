class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++){
            int a = nums1[i];
            int val = -1;
            int j = 0;
            for(;j<nums2.size();j++){
                if(nums2[j]==a){
                    break;
                }
            }
            
            for(;j<nums2.size();j++){
                if(nums2[j]>a){
                    val = nums2[j];
                    break;
                }
            }
            ans.push_back(val);
        }

        return ans;
    }
};