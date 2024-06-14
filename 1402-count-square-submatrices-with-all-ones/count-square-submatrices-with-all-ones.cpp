class Solution {
public:

    int n,m;

    bool calc(vector<vector<int>>& matrix ,int a , int b, int len){
        for(int i = a;i<a+len;i++){
            for(int j = b;j<b+len;j++){
                if(matrix[i][j]==0) return false;
            }
        }

        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int len = 1;len<=min(n,m);len++){
                    if(i+len>n || j+len>m){
                        break;
                    }
                    if(calc(matrix , i,j,len)){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};