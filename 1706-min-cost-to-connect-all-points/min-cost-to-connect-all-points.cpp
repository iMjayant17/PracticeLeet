class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int, int>, vector<tuple<int, int, int>>> adj;
        for (auto p : points) {
            int x = p[0];
            int y = p[1];
            for (auto q : points) {
                int xx = q[0];
                int yy = q[1];
                int wt = abs(x - xx) + abs(y - yy);
                adj[{x, y}].push_back({wt, xx, yy});
                // cout<<x<<" "<<y<<" "<<wt<<" "<<xx<<" "<<yy<<endl;
            }
        }

        int ans = 0;

        map<pair<int, int>, int> m;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({0, points[0][0], points[0][1]});

        while (!pq.empty()) {
            auto [wt, x, y] = pq.top();
            pq.pop();

            // cout<<wt <<" "<< m[{x,y}]<<endl;
            if (m[{x, y}])
                continue;
            // cout<<"sdfasdf"<<endl;
            m[{x, y}]++;
            ans += wt;

            for (auto& ed : adj[{x, y}]) {
                auto [wtt, xx, yy] = ed;
                // cout<<"sdafsdsdafdsf"<<" "<<m[{xx,yy}]<<endl;
                if (m[{xx, yy}])
                    continue;

                pq.push(ed);
            }
        }
        return ans;
    }
};