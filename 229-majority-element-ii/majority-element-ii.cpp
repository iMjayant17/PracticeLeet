class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = -1;
        int val2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for(auto i:nums){
            if(i==val1){
                cnt1++;
            }
            else if(i==val2){
                cnt2++;
            }
            else if(cnt1==0){
                val1 = i;
                cnt1 = 1;
            }
            else if(cnt2==0){
                val2 = i;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0,cnt2 = 0;
        for(auto i:nums){
            if(i==val1) cnt1++;
            if(val2==i) cnt2++;
        }
        vector<int> ans;
        if(cnt1>(n/3)) ans.push_back(val1);
        if(cnt2>(n/3) && val1!=val2) ans.push_back(val2);

        return ans;

    }
};