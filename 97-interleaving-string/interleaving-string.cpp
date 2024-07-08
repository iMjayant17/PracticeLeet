class Solution {
public:
    int dp[101][101][201];
    bool solve(int idx1 ,int idx2,int idx3, string s1,string s2,string s3){
        if(idx1>=s1.size() && idx2>=s2.size() && idx3>=s3.size()) return true;
        if(idx3>=s3.size()) return false;

        if(dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];

        bool a=false,b=false,c;
        for(int i = idx1;i<s1.size();i++){
            if(s1[i]!=s3[idx3+i-idx1]) break;
            a |= solve(i+1,idx2,idx3+i-idx1 + 1,s1,s2,s3);
        }

        for(int i = idx2;i<s2.size();i++){
            if(s2[i]!=s3[idx3+i-idx2]) break;
            b |= solve(idx1,i+1,idx3+i-idx2 + 1,s1,s2,s3);
        }
        return dp[idx1][idx2][idx3] = a|b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s1,s2,s3);
    }
};