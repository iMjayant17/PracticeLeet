class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return false;
        vector<int> pre(n,0);
        int sum = 0;
        for(int i = 0;i<pre.size();i++){
            sum+=nums[i];
            pre[i] = sum %k;
        }

        map<int ,int> m;
        m[0] = -1;
        for(int i = 0;i<pre.size();i++){
            if(m.find(pre[i])==m.end()){
                m[pre[i]] = i;
            }
            else{
                if(i-m[pre[i]]+1>2){
                    return true;
                }
            }
        }
        return false;
    }
};