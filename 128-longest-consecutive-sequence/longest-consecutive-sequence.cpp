class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]] = 1;
        }

        for(int i = 0;i<nums.size();i++){
           int val = nums[i];
           int cnt = 0;
           while(m[val]>0){
            if(m[val]>1){
                cnt+=m[val];
                break;
            }
            cnt++;
            m[val] = INT_MAX;
            val--;
           }
           m[nums[i]] = cnt;

        }

        for(auto i:m){
            if(i.second !=INT_MAX){
                ans = max(ans,i.second);
            }
        }
        return ans;
    }
};