class Solution {
public:
    int knightDialer(int n) {
        if(n==1) return 10; 
        const int M = 1e9+7;
        vector<vector<int>> temp = {{4, 6},    {6, 8}, {7, 9},    {4, 8},
                                    {0, 3, 9}, {},     {0, 1, 7}, {2, 6},
                                    {1, 3},    {2, 4}};
        vector<int> dp(10,1);
        for(int i = 2;i<=n;i++){
            vector<int> arr(10,0);
            for(int j =0;j<10;j++ ){
                for(auto k:temp[j]){
                    arr[j]= (arr[j] + dp[k])%M;
                }
            }
            dp = arr;
            
        }

        return accumulate(dp.begin(),dp.end(),0ll)%M;
    }
};