class Solution {
public:
    vector<vector<string>> ans;

    bool isSafeLeft(vector<string>& board, int i, int j) {
        while (i >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
        }
        return true;
    }

    bool isSafeDigo(vector<string>& board, int i, int j) {

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        return true;
    }

    bool isSafeRiDigo(vector<string>& board, int i, int j) {
        while (i >= 0 && j < board.size()) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }

    void solve(vector<string>& board, int idx) {
        if (idx >= board.size()) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {

            if (isSafeLeft(board, idx, i) && isSafeDigo(board, idx, i) &&
                isSafeRiDigo(board, idx, i)) {

                board[idx][i] = 'Q';
                solve(board, idx + 1);
                board[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
    }
};