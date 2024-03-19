class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        int maxi = INT_MIN;
        int cnt = 0;
        for(auto i:tasks){
            m[i]++;
            maxi = max(maxi,m[i]);
        }
        
        for(auto i:m){
            if(i.second == maxi){
                cnt++;
            }
        }
        int ans = (n+1) * (maxi-1);
        ans+=cnt;
        if(ans<=tasks.size()) return tasks.size();
        return ans;
        
    }
};