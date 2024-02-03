class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;      
        // for(int i = 0;i< k;i++){
        //     while(q.size()>0 && nums[q.back()]<=nums[i]){
        //         q.pop_back();
        //     }
        //     q.push_back(i);
        // }
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(i>=k){
            ans.push_back(nums[q.front()]);
            }
            while( q.size()>0 && i-q.front()>=k){
                q.pop_front();
            }
            while(q.size()>0 && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};