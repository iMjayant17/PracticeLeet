class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        int cnt = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==2) Q.push({i,j});
                if(grid[i][j]==1) cnt++;
            }
        }
        int ans = 0;
        if(Q.size()==0 && cnt == 0) return 0;
        while(Q.size()>0){

            int len = Q.size();
            for(int k = 0;k<len;k++){
                auto [i,j] = Q.front();
                Q.pop();
                if(i+1<grid.size()){
                    if(grid[i+1][j]==1){
                        grid[i+1][j] = 2;
                        Q.push({i+1,j});
                    }
                }
                if(i-1>=0){
                    if(grid[i-1][j]==1){
                        grid[i-1][j] = 2;
                        Q.push({i-1,j});
                    }
                }
                if(j+1<grid[0].size()){
                    if(grid[i][j+1]==1){
                        grid[i][j+1] = 2;
                        Q.push({i,j+1});
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1]==1){
                        grid[i][j-1] = 2;
                        Q.push({i,j-1});
                    }
                }
            }

            ans++;
        }

        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++ ){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans-1;
    }
};