class Solution {
public:
    int dp[305][12]={-1};
    int solve(vector<int>& jd, int d,int idx){
        if(d==1){
            int maxi = INT_MIN;
            for(int i = idx;i<jd.size();i++){
                maxi = max(maxi,jd[i]);
            }
            return maxi;
        }
        if(dp[idx][d]!= -1) return dp[idx][d];
        int final = INT_MAX;
        int ans = jd[idx];
        for(int i = idx;i<=jd.size()-d;i++){
            ans = max(ans,jd[i]);
            int aa = solve(jd,d-1,i+1);
            final = min(final, ans+aa);
        }
        return dp[idx][d] =  final;
    }

    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size()<d) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jd,d,0);
    }
};