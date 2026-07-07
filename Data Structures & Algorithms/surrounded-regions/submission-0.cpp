class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        // 1. Boundary Check
        // 2. Stop if it's not an 'O' (we only care about unvisited 'O's)
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        // Mark the current 'O' as safe by changing it to 'T'
        board[r][c] = 'T';
        
        // Dive in all 4 directions recursively
        dfs(board, r + 1, c, rows, cols); // Down
        dfs(board, r - 1, c, rows, cols); // Up
        dfs(board, r, c + 1, rows, cols); // Right
        dfs(board, r, c - 1, rows, cols); // Left
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Step 1: Border Patrol (Top and Bottom rows)
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c, rows, cols);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c, rows, cols);
        }
        
        // Step 1: Border Patrol (Left and Right columns)
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0, rows, cols);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1, rows, cols);
        }
        
        // Step 3: Cleanup the board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // It was surrounded! Capture it.
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // It was safe! Restore it.
                }
            }
        }
    }
};