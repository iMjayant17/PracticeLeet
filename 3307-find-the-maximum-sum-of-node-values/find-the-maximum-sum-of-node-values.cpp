class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;

        vector<pair<int,int>> vp;
        for(auto i:nums){
            int val = (i^k);
            vp.push_back({val-i , i});
        }
        sort(vp.rbegin(),vp.rend());
        for(int i=0;i<vp.size();i+=2){
            if(i+1>=vp.size()) return ans+vp[i].second ;
            if(vp[i].first + vp[i+1].first>=0){
                ans += vp[i].first + vp[i+1].first + vp[i].second + vp[i+1].second;
            }else{
                ans +=  vp[i].second + vp[i+1].second;
            }
        }

        return ans;
    }
};