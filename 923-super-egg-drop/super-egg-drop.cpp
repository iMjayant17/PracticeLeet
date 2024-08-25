class Solution {
public:
    int dp[105][10005];
    int solve(int k,int n){
        if(n<=1) return n;
        if(k==1) return n;
        if(dp[k][n]!= -1) return dp[k][n];
        int mini = 1000000;
        int s = 1,e = n;
        while(s+1<e){
            int mid = e - (e-s)/2;
            int broken = solve(k-1,mid-1);
            int notBroken = solve(k,n-mid);
            int val = max(broken,notBroken);
            mini = min(mini,val);
            if(broken<notBroken){
                s = mid;
            }
            else if(broken>notBroken){
                e = mid;
            }
            else{
                break;
            }
        }
        int broken1 = solve(k-1,s-1);
        int notBroken1 = solve(k,n-s);
        int val1 = max(broken1,notBroken1);
        int broken2 = solve(k-1,e-1);
        int notBroken2 = solve(k,n-e);
        int val2 = max(broken2,notBroken2);
        mini = min(mini,min(val1,val2));
        return dp[k][n] = 1+mini;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};