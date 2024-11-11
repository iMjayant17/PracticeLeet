class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int b) {
        int maxi = *max_element(nums.begin(),nums.end());
        
        vector<int> arr(maxi+5,0);
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
            int left = max(i-k,0);
            int right = min(i+k,maxi+3);

            arr[left]++;
            arr[right+1]--;
        }

        for(int i = 1;i<maxi+4;i++){
            arr[i]+=arr[i-1];
        }
        int ans = 0;

        for(int i = 0;i<maxi+4;i++){
            int val = m[i];
            val += min(max(0,arr[i]-val) , b);
            ans = max(ans,val);
        }

        return ans;
    }
};