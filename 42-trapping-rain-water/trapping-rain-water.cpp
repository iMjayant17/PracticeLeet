class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if(n<3) return ans;
        vector<int> maxileft(n,0);
        vector<int> maxiright(n,0);
        maxileft[0] = height[0];
        maxiright[n-1] = height[n-1];

        for(int i = 1;i<n;i++ ){
            maxileft[i] = max(maxileft[i-1],height[i]);
        } 

        for(int i = n-2;i>=0;i--){
            maxiright[i] = max(maxiright[i+1],height[i]);
        }

        for(int i = 1;i<n-1;i++){
            int check = min(maxileft[i-1],maxiright[i+1]);
            if(check>height[i]) ans+=(check -height[i]);
        }

        return ans;
    }
};