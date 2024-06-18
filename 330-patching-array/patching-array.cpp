class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int cnt = 0;
        int i = 0;
        while(sum<n && i<nums.size()){
            while(i<nums.size() && sum+1<nums[i] && sum<n){
                sum+= (sum+1);
                cnt++;
            }
            if(i<nums.size() && sum+1>=nums[i]){
                sum+= nums[i];
                i++;
            }

            if(i>=nums.size()){
                while( sum<n){
                sum += (sum+1);
                cnt++;
            }
            }
            
        }
        return cnt;
        
    }
};