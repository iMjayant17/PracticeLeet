class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> task;
        for(int i = 0;i<diff.size();i++){
            task.push_back({diff[i],p[i]});
        }
        sort(task.begin(),task.end());
        sort(w.begin(),w.end());
        int maxi = 0,ans = 0;
        int j = 0;
        for(int i = 0;i<w.size();i++){
            while(j<task.size() && w[i]>=task[j].first){
                maxi = max(maxi,task[j].second);
                j++;
            }
            ans+=maxi;
        }
        return ans;
    }
};