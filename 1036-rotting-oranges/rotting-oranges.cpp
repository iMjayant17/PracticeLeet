class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    Q.push({i,j});
                }
                if(grid[i][j]!=0) total++;
            }
        }
        int ans = 0;
        while(Q.size()>0){
            int sz = Q.size();
            for(int k = 0;k<sz;k++){
                auto [i,j] = Q.front();
                Q.pop();
                total--;
                if(i+1<n && grid[i+1][j]==1){
                    Q.push({i+1,j});
                    grid[i+1][j] = 2; 
                    
                } 

                if(j+1<m && grid[i][j+1]==1){
                    Q.push({i,j+1});
                    grid[i][j+1] = 2; 
                }

                if(i-1>=0 && grid[i-1][j]==1){
                    Q.push({i-1,j});
                    grid[i-1][j] = 2; 
                } 

                if(j-1>=0 && grid[i][j-1]==1){
                    Q.push({i,j-1});
                    grid[i][j-1] = 2; 
                }
            }
            ans++;
        }

        if(total) return -1;
        return max(0,ans-1);

    }
};