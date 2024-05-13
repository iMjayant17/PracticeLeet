class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[0] = -1;
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it:times){
            int ff = it[0];
            int ss = it[1];
            int wt = it[2];
            adj[ff].push_back({ss,wt});
        }
        // for(int i = 0;i<adj.size();i++){
        //     for(auto it:adj[i]){
        //         cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        // cout<<adj.size()<<endl;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [dis,node] = pq.top();

            // cout<<pq.size()<<" sdaggggg"<<endl;
            pq.pop();
            for(auto child:adj[node]){
                int d = child.second;
                int n_node = child.first;
                // cout<<node<<" "<< d<<".."<<n_node<<endl;

                if(dis+d<dist[n_node]){
                    dist[n_node] = dis+d;
                    pq.push({dist[n_node],n_node});
                }
            }
        }
        // for(auto i:dist){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int maxi = *max_element(dist.begin(),dist.end());
        return maxi==INT_MAX ? -1:maxi;

    }
};