class Solution {
public:

    int help(int n){
        int ans = 0;
        while(n){
            int dig = n%10;
            ans+= (dig*dig);
            n/=10;
        }
        return ans;
    } 

    bool isHappy(int n) {

        while(n>=10){
            n = help(n);
            
        }
        if(n==1 || n==7){
            return true; 
        }
        return false;
    }
};