class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][n+1];
        for(int dif = 0;dif<n;dif++){
            for(int i=0,j = i+dif ;j<n;i++,j++){
                if(dif==0){
                    dp[i][j] = arr[i];
                }
                else if(dif==1){
                    dp[i][j] = max(arr[i],arr[j]);
                }
                else{
                    int a = arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                    int b = arr[j] + min(dp[i][j-2],dp[i+1][j-1]);
                    dp[i][j] = max(a,b);
                }
            }
        }
        return dp[0][n-1];
    }
};