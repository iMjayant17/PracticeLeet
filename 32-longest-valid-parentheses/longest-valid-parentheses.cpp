class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0){return 0;}
        int n = s.size();
        vector<int>dp(n,0);
        dp[0] = 0;
        int ans = 0;
        for(int i = 1;i < n;i++){
           if(s[i] == '('){continue;}
           else{
                if(s[i-1] == '('){
                    if(i >=2){
                        dp[i] = dp[i-2] + 2;
                    }
                    else{dp[i] = 2;}
                }
                else{
                    if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
                        if(i - dp[i-1] - 2 >= 0){
                            dp[i] = dp[i - dp[i-1] - 2] + 2 + dp[i-1];
                        }
                        else{
                            dp[i] = dp[i-1] + 2;
                        }
                    }
                }
           }
           ans = max(ans,dp[i]);
        }
        return ans;
    }
};