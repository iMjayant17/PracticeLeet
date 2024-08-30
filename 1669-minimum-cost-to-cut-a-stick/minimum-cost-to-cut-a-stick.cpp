class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        reverse(cuts.begin(),cuts.end());
        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        int s = cuts.size();
        int dp[s][s];

        for(int diff = 1;diff<=s;diff++){
            for(int i = 0,j = i+diff;j<s;j++,i++){
                if(diff==1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = INT_MAX;
                    for(int via = i+1;via<j;via++){
                        dp[i][j] = min(dp[i][j] , dp[i][via] + dp[via][j]);
                    }
                    dp[i][j] += (cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][s-1];
    }
};