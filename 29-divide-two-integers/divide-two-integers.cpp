class Solution {
public:
    int divide(int x, int y) {
        long long A = x,B = y;
    // if(A==0) return 0;
    long long ans = 0,temp = 0;
    int sign = 1;
    if(A<0) sign = -sign;
    if(B<0) sign = -sign;
    A = abs(A);
    B = abs(B);
    
    for(long long i = 31;i>=0;i--){
        if( temp + (B<<i) <= A){
            temp += (B<<i);
            ans  += (1ll<<i);
        }
    }
    if(sign<0) ans = -ans;
    if(ans<INT_MIN || ans>INT_MAX) return INT_MAX;
    // return sign;
    return ans;
    }
};