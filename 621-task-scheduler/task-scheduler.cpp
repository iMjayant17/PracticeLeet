class Solution {
public:
    int leastInterval(vector<char>& tasks, int a) {
        vector<int> n(26, 0);
        for (char task : tasks) {
            n[task - 'A']++;
        }
        sort(n.rbegin(),n.rend());
        // cout<<n[0];
        // int maxf=n[0]-1;
        int idle=(n[0]-1)*a;
        for(int i=1;i<n.size();i++){
            idle-=min(n[0]-1,n[i]);
        }
          idle = max(0, idle);
        
        return tasks.size() + idle;
    }
};
