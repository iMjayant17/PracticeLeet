class Solution {
public:
vector<int> ans;
    void solve(int i, int j, vector<vector<int>>& matrix) {
        if (i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 ||
            matrix[i][j] == 1000) {
            return;
        }
        ans.push_back(matrix[i][j]);
        matrix[i][j]=1000;
        if(i<=j+1) solve(i,j+1,matrix);
        solve(i+1,j,matrix);
        solve(i,j-1,matrix);
        solve(i-1,j,matrix);

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        solve(0,0,matrix);
        return ans;
    }
};