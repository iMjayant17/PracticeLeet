class Solution {
public:
    int dp[105][105];
    int solve(int l,int r,vector<int>&cuts){
        if(l>=r) return 0;
        if(dp[l][r]!= -1) return dp[l][r];
        int mini = INT_MAX;
        for(int i = 0;i<cuts.size();i++){
            if(cuts[l]<cuts[i] && cuts[r]>cuts[i]){
                int val = solve(l,i,cuts) + solve(i,r,cuts);
                mini = min(mini,val);
            }
        }
        if(mini == INT_MAX) return 0;
        return dp[l][r] = mini + (cuts[r]-cuts[l]);
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        reverse(cuts.begin(),cuts.end());
        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        int r = cuts.size()-1;
        return solve(0,r,cuts);
    }
};