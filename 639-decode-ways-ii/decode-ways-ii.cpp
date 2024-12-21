class Solution {
    
public:
    int numDecodings(string s) {
        long long n = s.length();
        long long mod = 1e9 + 7;
        vector<long long> dp(n+1,0);
        if(s[0] == '0')return 0;
        if(s[0]>='0' and s[0]<='9'){
            dp[0] = 1;
        }
        if(s[0] == '*'){
            dp[0] = 9;
        }

        for(long long i=1; i<n; i++){
            if(s[i]=='*'){
                dp[i] = (dp[i]%mod + (9*dp[i-1])%mod + mod)%mod;
                if(s[i-1]=='*'){
                    dp[i] = (dp[i]%mod + (15*(i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                }
                else if(s[i-1]=='1'){
                    dp[i] = (dp[i]%mod + (9*(i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                }
                else if(s[i-1]=='2'){
                    dp[i] = (dp[i]%mod + (6*(i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                }
            }
            else{
                if(s[i]>='1' and s[i]<='9'){
                    dp[i] = (dp[i]%mod +dp[i-1]%mod + mod)%mod;
                }
                if(s[i-1]=='*'){
                    if(s[i]>='0' and s[i]<='6'){
                        dp[i] = (dp[i]%mod + (2*(i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                    }
                    else{
                        dp[i] = (dp[i]%mod+((i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                    }
                }
                else if(s[i-1]=='1'){
                    dp[i] = (dp[i]%mod + ((i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                }
                else if(s[i-1]=='2' and s[i]<='6'){
                    dp[i] = (dp[i]%mod + ((i-2>=0?dp[i-2]:1))%mod + mod)%mod;
                }
            }
            
        }

        return dp[n-1];
    }
};