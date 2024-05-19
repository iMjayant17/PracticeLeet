class Solution {
public:

    bool isPossible(vector<int>& tasks, vector<int>& workers, int pills, int strength,int n){
       if(n>workers.size()) return false;
        multiset<int> task,work;
        for(int i = 0;i<n;i++){
            task.insert(tasks[i]);
            work.insert(workers[i]);
        }
        while(task.size()>0){
            int wrk = *work.begin();
            int tsk = *task.begin();
            if(wrk<tsk){
                if(pills<=0) return false;
                wrk+= strength;
                pills--;

                auto idx = task.upper_bound(wrk);
                if(idx==task.begin()) return false;
                idx--;
                // cout<<*idx<<endl;
                work.erase(work.begin());
                task.erase(idx);
            }
            else{
                work.erase(work.begin());
                task.erase(task.begin());
            }
// agar value se delete krenge to saari value delete ho jayegi to 
// pointer se point kra krk ek ko hi delete krenge bs
            // for(auto i:work){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // for(auto i:task){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.rbegin(),workers.rend());
        
        int n = tasks.size();
        int s = 0,e = n;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(isPossible(tasks,workers,pills,strength,mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;
    }
};