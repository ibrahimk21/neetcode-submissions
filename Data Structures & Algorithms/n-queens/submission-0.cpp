class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col))
            {
                continue;
            }
            else
            {
                cols.insert(col);
                posDiag.insert(row + col);
                negDiag.insert(row - col);
                board[row][col] = 'Q';

                backtrack(n, row + 1, board, result);

                cols.erase(col);
                posDiag.erase(row + col);
                negDiag.erase(row - col);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n == 0) return result;
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, board, result);
        return result;
    }
};