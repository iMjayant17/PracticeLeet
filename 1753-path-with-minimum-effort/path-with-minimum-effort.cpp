class Solution {
public:

    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        auto isSafe = [&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>
        ,greater<tuple<int,int,int>>> pq;
        dist[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto [dis,i,j] = pq.top();
            pq.pop();
            int val = h[i][j];
            // h[i][j] = -1;
            for(auto d: dir){
                int x = i+d[0];
                int y = j+d[1];
                if(!isSafe(x,y) || h[x][y] == -1){
                    continue;
                } 

                if(max(dis,abs(val-h[x][y]))<dist[x][y]){
                    dist[x][y] = max(dis,abs(val-h[x][y]));
                    pq.push({max(dis,abs(val-h[x][y])),x,y});
                }


            }
            
        }

        return dist[n-1][m-1];
        
    }
};