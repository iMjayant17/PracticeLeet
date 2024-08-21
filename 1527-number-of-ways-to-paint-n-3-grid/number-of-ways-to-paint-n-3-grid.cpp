class Solution {
public:
    const int M = 1e9+7;
    int dp[5005][5][5][5];
    int solve(int n,int x,int y,int z){
        if(n==0) return 1;
        if(dp[n][x][y][z]!= -1) return dp[n][x][y][z];
        int ans = 0;
        vector<int> color={1,2,3};
        for(auto xx:color){
            if(xx==x) continue;
            for(auto yy:color){
                if(yy==y || yy==xx) continue;
                for(auto zz:color){
                    if(zz==z || zz==yy) continue;
                    ans = (ans+solve(n-1,xx,yy,zz))%M;
                }
            }
        }
        return dp[n][x][y][z]=ans;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0);
    }
};