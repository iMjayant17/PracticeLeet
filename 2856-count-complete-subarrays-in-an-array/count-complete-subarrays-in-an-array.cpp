class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int ans = 0;
        int t = s.size();
        s.clear();
        int n = nums.size();
        for(int i = 0;i<n;i++){
            set<int> check;
            for(int j = i;j<n;j++){
                check.insert(nums[j]);
                if(check.size()==t){
                    cout<<n-j<<endl;
                    ans+=(n-j);
                    break;
                }
            }
        }
        
        return ans;
    }
};