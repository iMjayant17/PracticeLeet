class Solution {
public:
    
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        n--;
        map<long long,long long> m;
        pq.push(1);
        m[1]++;
        while(n--){
            long long k = pq.top();
            pq.pop();
            m[k] = 0;
            if(m[1ll*k*2]==0){
                pq.push(1ll*k*2);
                m[1ll*k*2]++;
            }
            if(m[1ll*k*3]==0){
                pq.push(1ll*k*3);
                m[1ll*k*3]++;
            }
            if(m[1ll*k*5]==0){
                pq.push(1ll*k*5);
                m[1ll*k*5]++;
            }
        }

        return pq.top();


    }
};