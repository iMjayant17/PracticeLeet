class Solution {
public:
    int maxArea(vector<int>& height) {
        int e = height.size()-1;
        int s = 0;
        int ans = 0;
        while(s<e){
            ans = max(ans ,min(height[s] ,height[e]) * (e-s));
            if(height[e]<height[s]){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};