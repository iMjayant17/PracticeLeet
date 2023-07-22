class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n-1,0);
        for(auto i:nums){
            if(i-1>=n-1) return false;
            temp[i-1]++;
        }
        
        if(*min_element(temp.begin(),temp.end())==0 || temp[n-2]!=2 ){
            return false;
        }
        return true;
    }
};