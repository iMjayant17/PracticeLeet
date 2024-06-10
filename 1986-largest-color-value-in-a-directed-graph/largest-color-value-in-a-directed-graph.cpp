class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = colors.length();
        vector<int> indegree(n, 0);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        map<int, map<char, int>> m;
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                Q.push(i);
            }
            m[i][colors[i]]++;
        }
        int ans = 0, cnt = 0;
        while (Q.size() > 0) {
            int node = Q.front();
            Q.pop();
            cnt++;
            ans = max(ans, m[node][colors[node]]);

            for (auto child : adj[node]) {
                indegree[child]--;
                if (indegree[child] <= 0) {
                    Q.push(child);
                }

                for (auto j : m[node]) {

                    m[child][j.first] =
                        max(m[child][j.first],
                            m[node][j.first] + (colors[child] == j.first));
                }
            }
        }

        if (cnt < n)
            return -1;
        return ans;
    }
};