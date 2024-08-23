class Solution {
public:
int dp[505][505];
    int solve(vector<int> &arr,int l,int r){
        if(l==r) return arr[l];
        if(l>r) return 0;
        if(dp[l][r]!= -1) return dp[l][r];
        int a = arr[l] + min(solve(arr,l+2,r) ,solve(arr,l+1,r-1));
        int b = arr[r] + min(solve(arr,l,r-2) ,solve(arr,l+1,r-1));
        return dp[l][r]=max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(piles.begin(),piles.end(),0ll);
        int ans = solve(piles,0,piles.size()-1);
        return ans>sum-ans;
    }
};