class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string ,int> m;
        for(auto i:words){
            m[i]++;
        }
        priority_queue<pair<int,string>> pq;
        for(auto i: m){
            pq.push({i.second,i.first});
        }
        vector<string> ans;
        vector<stack<string>> v(11);
        while(pq.size()>0){
            pair<int,string> a;
            a = pq.top();
            cout<<a.first<<" "<<a.second<<endl;
            v[a.first].push(a.second);
            pq.pop();
        }
            
        

        for(int i = 10;i>=0;i-- ){
                
            while(v[i].size()>0){
                ans.push_back(v[i].top());
                v[i].pop();
                k--;
                if(k==0){
                    break;
                }
            }
            if(k==0){
                break;
            }
        }
        // while(v[2].size()>0){
        //     cout<<v[2].top()<<endl;
        //         v[2].pop();
        // }
        return ans;
    }
};