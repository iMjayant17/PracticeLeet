class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        for(int i = 0;i<scores.size();i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int> dp(ages.size(),0);
        dp[0] = arr[0].second;
        for(int i = 1;i<ages.size();i++){
            int maxi = 0;
            for(int j = 0;j<i;j++){
                if(arr[j].second <=  arr[i].second){
                    maxi = max(maxi,dp[j]);
                }
            }
            dp[i] = maxi+arr[i].second;
        }
        return *max_element(dp.begin(),dp.end());

    }
};