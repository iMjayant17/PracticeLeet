class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> Q;
        int ans  =0;
        for(int i = 0;i<nums.size();i++){
            
            while(Q.size() >0 && Q.front()<i-k+1){
                Q.pop();
            }
            int s = Q.size();
            if(s&1){
                nums[i] = 1-nums[i];
            }

            if(nums[i]==0){
                ans++;
                Q.push(i);
            }

        }
        while(Q.size() >0 && Q.front()<nums.size()-k+1){
                Q.pop();
        }
        if(Q.size()>0) return -1;
        return ans;

    }
};