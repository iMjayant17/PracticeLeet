class Solution {
public:
    // int dp[100005][5];
    int n;
    int solve(vector<int>& arr,int idx,int t,vector<vector<int>> &dp){
        if(t<=0 || idx>=n) return 0;
        if(dp[idx][t]!= -1) return dp[idx][t];
        int a = 0,b = 0,c = 0,d = 0;
            d = solve(arr,idx+1,t,dp);
        if(t%2==1){
            a = arr[idx] + solve(arr,idx+1,t-1,dp);
        }
        else{
            a = solve(arr,idx+1,t-1,dp)-arr[idx];
        }
        return dp[idx][t]=max(a,d);
    }

    int maxProfit(vector<int>& prices) {
        // memset(dp,-1,sizeof(dp));
        n = prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(5,-1));
        return solve(prices,0,4,dp);
    }
};