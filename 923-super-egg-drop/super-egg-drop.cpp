class Solution {
public:
    int dp[105][10005];
    int solve(int k,int n){
        if(n<=1) return n;
        if(k==1) return n;
        if(dp[k][n]!= -1) return dp[k][n];
        int mini = INT_MAX;
        int s = 1,e = n;
        while(s<=e){
            int mid = e - (e-s)/2;
            int broken = solve(k-1,mid-1);
            int notBroken = solve(k,n-mid);
            int val = max(broken,notBroken);
            if(broken<notBroken){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mini = min(mini,val);
        }
        return dp[k][n] = 1+mini;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};