class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int k = nums.size();
        for(int i = 0;i<k;i++){
            nums.push_back(nums[i]);
        }
        // nums = nums+nums;
        vector<int> temp(nums.size());
        int n = nums.size();
        for(int i  = n-1;i>=0;i--){
            while(s.size()>0  &&  nums[s.top()%k]<= nums[i]){
                s.pop();
            }
            if(s.size()==0){
                temp[i] = -1;
            }
            else{
                temp[i] = nums[s.top()%k];
            }
            s.push(i);
        }
        vector<int> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};