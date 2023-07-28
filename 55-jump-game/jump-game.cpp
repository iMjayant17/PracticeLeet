class Solution {
public:
    bool canJump(vector<int>& nums) {

            stack<int> s;
            int n = nums.size();
           
            // if(nums[0]==0 && nums.size()>1){
            //     return false;
            // }
            
            for(int i = n-2;i>=0;i--){
                if(nums[i]==0){
                    s.push(i);
                }
                else{
                    while(s.size()>0 && s.top()<i+nums[i]){
                        s.pop();
                    }
                }

            }

            if(s.size()==0) return true;
            else{
                return false;
            }

































        // vector<int> ind;
        // int n = nums.size();
        // if(nums[0] ==0 && n>1) return false;
        // for(int i =n-2;i>=0;i--){
        //     if(nums[i]==0){
        //         ind.push_back(i+1);
        //         continue;
        //     }
        //     while(ind.size()>0 && ind.back()<= i+ nums[i] ){
        //         ind.pop_back();
        //     }
        // }

        // if(ind.size()==0) return true;
        // return false;
    }
};