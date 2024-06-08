class Solution {
public:
    int n;
    int dp[505][505][30];
    int solve(vector<int> &nums,int idx,int last,int k){
        if(idx>=n) return 0;

        if(dp[idx][last+1][k] != -1) return dp[idx][last+1][k];
        int p = 0,q = 0;
        int include= 0,exclude = 0;

       if(last == -1){
            include = 1 + solve(nums,idx+1,idx,k);
            exclude = solve(nums,idx+1,last,k);
       }
       else{
            if(nums[idx]==nums[last]){
                include = 1 + solve(nums,idx+1,idx,k);
                exclude = 0 + solve(nums,idx+1,last,k);
            }
            else{
                if(k>0) include = 1 + solve(nums,idx+1,idx,k-1);
                exclude = 0 + solve(nums,idx+1,last,k);

            }
       }

        return dp[idx][last+1][k] = max(include,exclude);

    }

    int maximumLength(vector<int>& nums, int k) {
        // map<int,int> m;
        n = nums.size();
        // vector<int> arr(n,0);
        // arr[0] = 1;
        // for(int i = 1;i<n;i++){
        //     int maxi = 0;
        //     int non = 0;
        //     for(int j = 0;j<i;j++){
        //         if(nums[j]==nums[i]){
        //             maxi = max(maxi,arr[j]);
        //         }
        //         else{
        //             non = max(non,arr[j]);
        //         }
        //     }
        //     arr[i] = maxi+1;
        // }

        // for(auto i:arr){
        //     cout<<i<<" ";
        // }
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,-1,k);

    //    if(n==0) return 0;
    //    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    //    for(int i = 0;i<n;i++){
    //     dp[i][0] = 1;
    //    }

    //    int maxi = 1;
    //    for(int i = 1;i<n;i++){
    //     for(int j = 0;j<k+1;j++){
    //         dp[i][j] = 1;
    //         for(int p = 0;p<i;p++){
    //             if(nums[p]==nums[i]){
    //                 dp[i][j] = max(dp[i][j],dp[p][j] + 1);
    //             }
    //             else if(j>0){
    //                 dp[i][j] = max(dp[i][j] ,dp[p][j-1] + 1);
    //             }
    //         }

    //         maxi = max(maxi,dp[i][j]);
    //     }
    //    }
    //     return maxi;
return ans;
    }
};