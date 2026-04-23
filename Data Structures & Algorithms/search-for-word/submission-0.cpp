class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index)
    {
        if (index == word.size()) return true;
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool result = dfs(board, word, i + 1, j, index + 1) ||
                      dfs(board, word, i, j + 1, index + 1) ||
                      dfs(board, word, i - 1, j, index + 1) ||
                      dfs(board, word, i, j - 1, index + 1);
        

        board[i][j] = temp;
        return result;

    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        int rows = board.size();
        int cols = board[0].size();
        if(word.size() > rows * cols) return false;


        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == word[0]) 
                {
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }
};