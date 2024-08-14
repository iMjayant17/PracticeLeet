class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            int ans = 9;
            for(int j = 1;j<i;j++){
                ans = ans*(10-j);
            }     
            dp[i] = ans+dp[i-1];
        }
        return dp[n];
        
    }
};