class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int winsize = k+1;

        map<int,int> m;

        for(int i = 0;i<min(winsize,n);i++){
            if(m[nums[i]]>0){
                return true;
            }
            m[nums[i]]++;
        }

        for(int i = 0;i<(n- winsize);i++){
            m[nums[i]] = 0;
            if(m[nums[i+winsize]]>0){
                return true;
            }
            m[nums[i+winsize]]++;
        }        

        return false;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int n = nums.size();
        // int win = k+1;
        // map<int,int> m;
        // for(int i= 0;i<min(win,n);i++ ){
        //     if(m[nums[i]]>0){
        //         return true;
        //     }
        //     m[nums[i]]++;
        // }
        // if(k>=n) return false;

        // for(int i = win;i<n;i++){
        //     m[nums[i-win]] = 0;
        //     if(m[nums[i]]>0){
        //         return true;
        //     }
        //     m[nums[i]]++;
        // }

        // return false;
    }
};