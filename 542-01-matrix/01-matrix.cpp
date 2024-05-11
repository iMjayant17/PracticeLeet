class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> Q;
        vector<vector<int>> ans = mat;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    Q.push({i,j});
                }
            }
        }
        int cnt = 0;
        while(Q.size()>0){
            int len = Q.size();
            
            for(int k = 0;k<len;k++){

                auto [i,j] = Q.front();
                Q.pop();
                
                if(mat[i][j]!=0){
                    ans[i][j] = cnt;
                    mat[i][j]=0;
                }
                if(i+1<mat.size() && mat[i+1][j]!=0){
                    Q.push({i+1,j});
                }
                if(i-1>=0 && mat[i-1][j]!=0){
                    Q.push({i-1,j});
                }
                if(j+1<mat[0].size() && mat[i][j+1]!=0){
                    Q.push({i,j+1});
                }
                if(j-1>=0 && mat[i][j-1]!=0){
                    Q.push({i,j-1});
                }


            }
            cnt++;
        }

        return ans;
    }
};