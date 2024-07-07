class Solution {
public:
    int numWaterBottles(int a, int b) {
        int ans = 0;
        int e = 0;
        while(a>0){
            ans+=a;
            e += a;
            a = 0;
            a = (e/b);
            e = e%b;
        }
        return ans;
    }
};