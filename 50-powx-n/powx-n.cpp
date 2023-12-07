class Solution {
public:
    double myPow(double x, int n) {
        int b = n;
        n = abs(n);
        double ans = 1;
        double k = x;
        while(n>0){
            if(n&1){
                ans*=k;
            }
            k = k*k;
            n = n>>1;
        }
        if(b<0){
            return 1.0/ans;
        }
        return ans;
        
    }
};