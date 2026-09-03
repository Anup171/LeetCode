class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols ||
            board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'S';
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        for (auto [dr, dc] : directions) {
            dfs(row + dr, col + dc, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int col = 0; col < cols; col++) {
            dfs(0, col, board);
            dfs(rows - 1, col, board);
        }
        for (int row = 0; row < rows; row++) {
            dfs(row, 0, board);
            dfs(row, cols - 1, board);
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } 
                else if (board[row][col] == 'S') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};