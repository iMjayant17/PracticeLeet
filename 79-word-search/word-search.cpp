class Solution {
public:
    bool find(vector<vector<char>>& board,string s,int i ,int j,int idx){
        if(idx>=s.length()){
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='.'){
            return false;
        }
        // int temp = idx;
        bool a = false,b= false,c= false,d= false;
        if(s[idx] == board[i][j]){
            // temp++;
            char ch = board[i][j];
            board[i][j] = '.';
        a = find(board,s,i+1,j,idx+1);
        board[i][j] = ch;
        board[i][j] = '.';
         b = find(board,s,i-1,j,idx+1);
         board[i][j] = ch;
         board[i][j] = '.';
         c = find(board,s,i,j+1,idx+1);
         board[i][j] = ch;
         board[i][j] = '.';
         d = find(board,s,i,j-1,idx+1);
         board[i][j] = ch;
        }
         
        if(a || b ||  c ||  d){
            return true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                bool ans = find(board,word,i,j,0);
                if(ans) return true;
            }
        }
        return false;
    }
};