class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]++;
        int sum = 0;
        int ans = 0;
        
        for(auto i:nums){
            sum+=i;
            int p = sum%k;
            if(p<0) p+=k;

            ans += m[p];
            m[p]++;
        }



        return ans;
    }
};