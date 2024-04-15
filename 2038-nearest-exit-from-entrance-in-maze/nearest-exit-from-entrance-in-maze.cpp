class Solution {
public:

void print(vector<vector<char>>& grid){
    for(auto i: grid){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
    int nearestExit(vector<vector<char>>& grid, vector<int>& e) {

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int ans = 0;

        queue<pair<int, int>> q;
        if (grid[e[0]][e[1]] == '+')
            return -1;

        q.push({e[0], e[1]});
        grid[e[0]][e[1]] = '+';

        while (q.size()) {
            
            int cnt = q.size();
            for (int l = 0; l < cnt; l++) {

                auto [i, j] = q.front();
                q.pop();
                if ((i == grid.size() - 1) || (j == grid[0].size() - 1) ||
                    (i == 0) || (j == 0)) {
                    if (i != e[0] || j != e[1])
                        return ans;
                }
                for (int p = 0; p < 4; p++) {

                    int ii = i + dir[p][0];
                    int jj = j + dir[p][1];
                    if (ii >= grid.size() || ii < 0 || jj >= grid[0].size() ||
                        jj < 0)
                        continue;
                    if (grid[ii][jj] == '+')
                        continue;
                    q.push({ii, jj});
                    grid[ii][jj] = '+';
                }

                // print(grid);
            }
            ans++;
        }

        return -1;
    }
};