class Solution {
public:
    void boundaryDFS(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'S';
        boundaryDFS(i + 1, j, board);
        boundaryDFS(i, j + 1, board);
        boundaryDFS(i - 1, j, board);
        boundaryDFS(i, j - 1, board);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) {
            return;
        }
        for(int i = 0; i < board[0].size(); i++) {
            if(board[0][i] == 'O') {
                boundaryDFS(0, i, board);
            }
            if(board[board.size() - 1][i] == 'O') {
                boundaryDFS(board.size() - 1, i, board);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') {
                boundaryDFS(i, 0, board);
            }
            if(board[i][board[i].size() - 1] == 'O') {
                boundaryDFS(i, board[i].size() - 1, board);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }  
    }
};
