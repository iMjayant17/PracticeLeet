class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int n = nums2.size();
        vector<int> temp(n);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.size()==0){
                temp[i] = -1;
                m[nums2[i]] = temp[i];
            }
            else{
                temp[i] = s.top();
                m[nums2[i]] = temp[i];
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i:nums1){
                ans.push_back(m[i]);
        }
        return ans;
    }
};