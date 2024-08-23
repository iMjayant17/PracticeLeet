class Solution {
public:
    long long dp[205][205];
    long long solve(long long l,long long r,long long n){
        if(l==r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        long long ans = INT_MAX;
        for(long long i = l;i<=r;i++){
            long long a = 0,b = 0 ,c = 0;
            if(i>l) a = i + solve(l,i-1,n);
            if(i<r) b = i + solve(i+1,r,n);
            ans = min(ans,max({a,b}));
        }
        return dp[l][r]=ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,n);
    }
};