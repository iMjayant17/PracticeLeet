class Solution {
public:
    const int M = 1e9+7; 
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum = ((sum)%M + (nums[j])%M)%M;
                temp.push_back(sum%M);
            }
        }
        sort(temp.begin(),temp.end());
        int ans = 0;
        for(int i = left-1;i<=right-1;i++){
                ans = ((ans%M) + (temp[i]%M))%M;
        }
        return ans;
    }
};