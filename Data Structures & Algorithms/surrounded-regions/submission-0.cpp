class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        // Boundary check + Only visit 'O'
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') 
            return;

        // Mark as Safe (Temporary symbol '#')
        board[r][c] = '#';

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // 1. Run DFS only on Borders (First/Last Row & Col)
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);       // Left col
            if(board[i][n-1] == 'O') dfs(board, i, n-1);   // Right col
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j);       // Top row
            if(board[m-1][j] == 'O') dfs(board, m-1, j);   // Bottom row
        }

        // 2. Flip everything else
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';  // Trapped!
                if(board[i][j] == '#') board[i][j] = 'O';  // Safe!
            }
        }
    }
};