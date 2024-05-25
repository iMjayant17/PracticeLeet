class Solution {
public:
    typedef tuple<int, int, int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto ed : flights) {
            adj[ed[0]].push_back({ed[1], ed[2]});
            // adj[ed[1]].push_back({ed[0],ed[2]});
        }
        priority_queue<P, vector<P>, greater<P>> Q;
        // cost , node
        vector<pair<bool, int>> visited(n, {false, -1});
        Q.push({0, 0, src});
        int ans = INT_MAX;
        while (Q.size() > 0) {
            auto [stop, cost, node] = Q.top();
            // cout<<cost<<" "<<stop<<" "<<node<<endl;
            Q.pop();

            if (stop > k + 1)
                break;
            if (node == dst) {
                ans = min(ans, cost);
                continue;
            }
            //  if(visited[node]==true){
            //     cout<<node<<endl;
            //     continue;
            // }
            // visited[node] = true;
            for (auto [child, price] : adj[node]) {
                if (visited[child].first == false && visited[child].second == (-1)) {
                    if (stop <= k) {
                        Q.push({stop + 1, cost + price, child});
                        visited[child] = {true,cost+price};
                    }
                }
                else if(visited[child].first == true){
                    if(visited[child].second>cost+price){
                        if (stop <= k) {
                        Q.push({stop + 1, cost + price, child});
                        visited[child] = {true,cost+price};
                    }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};