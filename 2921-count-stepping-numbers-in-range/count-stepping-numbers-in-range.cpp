class Solution {
public:
#define M 1000000007

int dp[15][105][2];
    int dfs(string s, int prev = 11, int idx = 0, int tight = 1,
            bool f = false) {
        if (idx >= s.length()) {
            return 1;
        }
        if(dp[prev][idx][tight] != (-1)) return dp[prev][idx][tight];
        if (prev == 11 && idx > 0) {
            tight = 0;
        }
        if (tight == 1) {
            long long ans = 0;
            for (int i = 0; i <= (s[idx] - '0'); i++) {
                int flg = 0;
                if (i == (s[idx] - '0'))
                    flg = 1;

                if (idx == 0) {
                    if(i==0){

                    ans = (ans + 1ll * dfs(s, 11, idx + 1, flg) % M);
                    }
                    else{
                        ans = (ans + 1ll * dfs(s, i, idx + 1, flg) % M);
                    }
                } else {
                    if (abs(prev - i) == 1) {
                        ans = (ans + 1ll * dfs(s, i, idx + 1, flg) % M);
                    }
                }
            }

            return dp[prev][idx][tight] =  ans % M;
        } else {
            long long ans = 0;
            for (int i = 0; i <= 9; i++) {
                int flg = 0;

                if (abs(prev - i) == 1) {
                    ans = (ans + 1ll * dfs(s, i, idx + 1, flg) % M);
                } else if (prev == 11) {
                    if (i == 0) {

                        ans = (ans + 1ll * dfs(s, 11, idx + 1, flg) % M);
                    } else {
                        ans = (ans + 1ll * dfs(s, i, idx + 1, flg) % M);
                    }
                }
            }
            return dp[prev][idx][tight] =  ans % M;
        }
        return 11;
    }
    int countSteppingNumbers(string low, string high) {

        memset(dp,-1,sizeof(dp));
        int cnt = 1;
        int i = low.length()-1 ;
        while(i>=0 && cnt>0){
            if(low[i]>='1'){
                low[i]--;
                cnt = 0;
            }
            else{
                
                
                    low[i] = '9';
                
            }
            i--;
        }
        // cout<<low<<endl;
        // string s = to_string(a);
        int h = dfs(high);
        memset(dp,-1,sizeof(dp));
        int l = dfs(low);
        // cout << dfs(low) << endl;
        return (h-l+M)%M;
        return 0;
    }
};