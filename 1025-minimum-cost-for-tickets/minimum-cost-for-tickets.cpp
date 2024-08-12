class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& arr) {
        int n = days.size();
        vector<int> dp(n);
        dp[0] = min({arr[0],arr[1],arr[2]});
        for(int i = 1;i<days.size();i++){
            int today = days[i];
            int a = arr[0],b = arr[1] , c = arr[2];
            for(int j = i-1;j>=0;j--){
                if(today-days[j]>=1){
                    a += dp[j];
                    break;
                }
            }

            for(int j = i-1;j>=0;j--){
                if(today-days[j]>=7){
                    b += dp[j];
                    break;
                }
            }

            for(int j = i-1;j>=0;j--){
                if(today-days[j]>=30){
                    c  += dp[j];
                    break;
                }
            }

            dp[i] = min({a,b,c});
        }
        return dp[n-1];
    }
};