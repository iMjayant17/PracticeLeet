class Solution {
public:
    int passThePillow(int n, int time) {
        int t = 2*n -2;
        time = time%t;
        if(time<=n-1){
            return time+1;
        } 
        else{
            return n-(time-n+1);
        }
    }
};