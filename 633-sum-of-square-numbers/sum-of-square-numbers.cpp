class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0;i<=sqrt(c);i++){
            int val = i*i;
            int dif = c- val;
            int sq = sqrt(dif);
            if(sq*sq == dif) return true;
        }
        return false;
    }
};