class Solution {
public:
void dfs(vector<vector<int>>& matrix,vector<int> &ans,int i,int j){
    if(i<0 || i>=matrix.size() || j<0||j>=matrix[0].size() || matrix[i][j]==INT_MAX ){
        return;
    }
    ans.push_back(matrix[i][j]);
    matrix[i][j] = INT_MAX;
    if(i<=j+1)
        dfs(matrix,ans,i,j+1);
    dfs(matrix,ans,i+1,j);
    dfs(matrix,ans,i,j-1);
    dfs(matrix,ans,i-1,j);
}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        dfs(matrix,ans,0,0);
        return ans;
    }
};