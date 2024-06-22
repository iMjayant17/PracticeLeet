class Solution {
public:
    int dp[605][105][105];
    int solve(int idx,vector<pair<int,int>> &arr ,int z,int o){
        if(idx>=arr.size()) return 0;
        if(dp[idx][z][o] != -1) return dp[idx][z][o];
        int include = 0,exclude = 0;

        if(z>=arr[idx].first && o>=arr[idx].second){
            include = 1 + solve(idx+1,arr,z-arr[idx].first,o-arr[idx].second);
        }
        exclude = 0 + solve(idx+1,arr,z,o);

        return  dp[idx][z][o] = max(include,exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // int n = strs.size();
        vector<pair<int,int>> arr;
        for(auto i:strs){
            int cnt0 = 0,cnt1 = 0;
            for(auto j:i){
                if(j=='0') cnt0++;
                else cnt1++;
            }
            arr.push_back({cnt0,cnt1});
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,arr,m,n);

    }
};