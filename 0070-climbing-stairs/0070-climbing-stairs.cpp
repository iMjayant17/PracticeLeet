class Solution {
public:

    // int solve(int n,vector<int> &dp){
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     if(n==3) return 3;
    //     if(dp[n]!=(-1)) return dp[n];

    //     dp[n] = solve(n-1,dp)+solve(n-2,dp);
    //     return dp[n];
    //     // memoization

    // }

    int solve2(int n){
        vector<int> dp(n+5,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        return solve2(n);
    }
};

// recursion (exponential) -> memoization (O(n) se thoda  jyada )
//  -> tabulation (o(n)) -> space optimization(O(n) O(1))