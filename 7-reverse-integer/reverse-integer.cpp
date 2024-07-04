class Solution {
public:
    int reverse(int x) {
        int neg = (x<0)? -1:1;

        x = abs(x);
        int ans = 0;
        while(x){
            int d = x%10;
            if(ans>INT_MAX/10 || ans>INT_MAX/10 && neg== -1) return 0;
            ans = ans*10 + d;
            x/=10;
        }
        return ans*neg;
    }
};