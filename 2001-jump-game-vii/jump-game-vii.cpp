class Solution {
public:
    
//     bool check(string s, int minJump, int maxJump,int index,vector<bool> &dp){
//         if(index>s.length()){
//             return false;
//         }
//         if(index==s.length()-1){
//             return true;
//         }
        
// //         if(dp[index]==false){
// //             return false;
// //         }
        
//         bool ans = false;
//         for(long long i = index+minJump ; i<=  min(index + maxJump, (int)s.length()-1);i++){
//             if(s[i]=='1' || dp[i]==false){ continue;}
//             if(check(s,minJump,maxJump,i,dp) ==true ){
//              return true;   
//             }
//             dp[i] = false;
//         }
    
//     return false;
//     }
    
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i = 1;i<n;i++){
            dp[i] = dp[i-1];
            if(s[i]=='0'){
                int val1 = max(i-maxJump,0);
                int val2 = i-minJump;
                if(val1>val2 || val2<0){
                    continue;
                }
                if(  dp[val1]!=dp[val2] || dp[val1]==dp[val2] && dp[val1]==val1){
                    dp[i] = i;
                }
            }
        }

        if(dp[n-1]==n-1){
            return true;
        }
        return false;
    }
};