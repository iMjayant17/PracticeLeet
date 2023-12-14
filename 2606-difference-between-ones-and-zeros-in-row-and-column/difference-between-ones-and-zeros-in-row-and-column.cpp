class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<m;j++){
                if(grid[i][j]){
                    cnt++;
                }
            }
            row[i] = cnt;
        }
        
        
        for(int i = 0;i<m;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(grid[j][i]){
                    cnt++;
                }
            }
            col[i] = cnt;
        }
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<m;j++){
                grid[i][j] = row[i]+col[j] - (n-row[i]) - (m-col[j]);
            }
         
        }
        
        
        return grid;
        
        
        
    }
};