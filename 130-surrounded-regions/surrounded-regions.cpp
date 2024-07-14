class Solution {
public:
    void fill(vector<vector<char>>& board,int i ,int j){
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
            return;
        }
        if(board[i][j]!='O') return;
        board[i][j] = '1';
        fill(board,i+1,j);
        fill(board,i-1,j);
        fill(board,i,j+1);
        fill(board,i,j-1);
        
    }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            if(board[i][0]=='O'){
                fill(board,i,0);
            }
        }
        for(int i = 0;i<n;i++){
            if(board[i][m-1]=='O'){
                fill(board,i,m-1);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[0][i]=='O'){
                fill(board,0,i);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[n-1][i]=='O'){
                fill(board,n-1,i);
            }
        }
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]=='1'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};