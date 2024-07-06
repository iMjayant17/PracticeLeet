class Solution {
public:
    double myPow(double x, int n) {
       int neg = n<0?1:0;
       n = abs(n);
       double ans = 1;
       while(n){
        if(n&1){
            ans*=x;
        }
        x = x*x;
        n=n>>1;
       }

       if(neg) return (1/ans);

       return ans;
        
    }
};