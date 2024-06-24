class Solution {
public:

    set<int> div(int n){
        set<int> s;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i==0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        return s;
    }
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==2) return 2;
        if(n==3) return 3;
        vector<int> dp(n+1,0);
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4;i<=n;i++ ){
            dp[i] = i;
            set<int> s = div(i);
            for(auto j:s){
                dp[i] = min(dp[i],dp[j] + i/j);
            }
        }

        for(auto i:dp){
            cout<<i<<" ";
        }
        cout<<endl;
        return dp[n];
    }
};