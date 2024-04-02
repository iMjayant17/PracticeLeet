class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        string ans = "";
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int diff=0; diff<n; diff++){
            for(int i=0, j=diff; j<n; i++, j++){
                if(diff==0){
                    dp[i][j] = 1;
                }
                else if(diff==1){
                    if(s[i]==s[j]) dp[i][j] = 2;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]>0){
                        dp[i][j] = 2 + dp[i+1][j-1]; 
                    }
                }

                if( dp[i][j]>0 && j-i+1 > maxi){
                    maxi = j-i+1;
                    ans = s.substr(i,maxi);
                }
            }
        }
        // for(auto i:dp){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
        
    }
};