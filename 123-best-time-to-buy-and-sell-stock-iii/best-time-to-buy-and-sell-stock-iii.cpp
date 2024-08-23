class Solution {
public:
    int dp[100005][6];
    int solve(vector<int>& arr,int idx,int t){
        if(t==0 || idx>=arr.size()) return 0;
        if(dp[idx][t]!= -1) return dp[idx][t];
        int a = 0,b = 0,c = 0,d = 0;
        if(t&1){
            b = arr[idx] + solve(arr,idx+1,t-1);
            c = solve(arr,idx+1,t);
        }
        else{
            a = solve(arr,idx+1,t-1)-arr[idx];
            d = solve(arr,idx+1,t);
        }
        return dp[idx][t]=max(a,max(b,max(c,d)));
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,4);
    }
};