class Solution {
public:
    int solve(int amount,vector<int>&coins,int j,vector<vector<int>> &dp){
        if(amount==0 && j<coins.size()){
            return 1;
        }
        if(amount<0 || j>=coins.size()) return 0;
        // cout<<amount<<endl;

        if(dp[j][amount]!=INT_MIN) return dp[j][amount];

        
        int ans = solve(amount-coins[j],coins,j,dp) + solve(amount,coins,j+1,dp);
        
        return dp[j][amount] = ans;
        
    }

    int change(int amount, vector<int>& coins) {
        
    vector<vector<int>> dp(301,vector<int>(5001,INT_MIN));
        return solve(amount,coins,0,dp);
    }
};