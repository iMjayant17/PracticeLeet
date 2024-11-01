class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast){
                fast = nums[0]; 
                while(slow!=fast){
                    slow = nums[slow];
                    fast = nums[fast];
                    if(slow==fast) return slow;
                }
                return slow;
            }
        }while(slow!=fast);
        return -1;
    }
};