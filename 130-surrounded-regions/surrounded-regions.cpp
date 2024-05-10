class Solution {
public:
    bool chk(vector<vector<char>>& board,int i ,int j){
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
            return false;
        }
        if(board[i][j]=='X') return true;
        board[i][j]='X';
        bool a = chk(board,i+1,j);
        board[i][j]='O';
        if(!a) return false;
        board[i][j]='X';
        bool b = chk(board,i-1,j);
        board[i][j]='O';
        if(!b) return false;
        board[i][j] = 'X';
        bool c = chk(board,i,j+1);
        board[i][j]='O';
        if(!c) return false;
        board[i][j] = 'X';
        bool d = chk(board,i,j-1);
        board[i][j]='O';
        if(!d) return false;
        return true;
    }


    void fill(vector<vector<char>>& board,int i ,int j){
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
            return;
        }
        if(board[i][j]=='X') return;
        board[i][j] = 'X';
        fill(board,i+1,j);
        fill(board,i-1,j);
        fill(board,i,j+1);
        fill(board,i,j-1);
        
    }
    void fill2(vector<vector<char>>& board,int i ,int j){
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0){
            return;
        }
        if(board[i][j]!='O') return;
        board[i][j] = '1';
        fill2(board,i+1,j);
        fill2(board,i-1,j);
        fill2(board,i,j+1);
        fill2(board,i,j-1);
        
    }
    void solve(vector<vector<char>>& board) {
        // for(int i = 0;i<board.size();i++){
        //     for(int j = 0;j<board[0].size();j++){
        //         if(board[i][j]=='O'){
        //             if(chk(board,i,j)){
        //                 fill(board,i,j);
        //                 // cout<<i<<" "<<j<<endl;
        //             }
        //             else{
        //                 // cout<<i<<" "<<j<<endl;
        //                 fill2(board,i,j);
        //             }
        //         }
        //     }
        // }
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            if(board[i][0]=='O'){
                fill2(board,i,0);
            }
        }
        for(int i = 0;i<n;i++){
            if(board[i][m-1]=='O'){
                fill2(board,i,m-1);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[0][i]=='O'){
                fill2(board,0,i);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[n-1][i]=='O'){
                fill2(board,n-1,i);
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