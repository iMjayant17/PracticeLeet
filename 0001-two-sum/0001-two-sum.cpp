class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy;
        copy = nums;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int check1 = 0;
        int check2 = 0;
        vector<int> ans;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                check1 = nums[i];
                check2 = nums[j];
                break;
            }
        }
        for(int i = 0;i<nums.size();i++){
            cout<<copy[i]<<endl;
            if(copy[i]==check1){
                ans.push_back(i);
                break;
            }
        }

        for(int i = nums.size()-1 ;i>=0;i--){
            if(copy[i]==check2){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};