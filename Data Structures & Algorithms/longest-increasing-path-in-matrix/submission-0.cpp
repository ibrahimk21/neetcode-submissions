class Solution {
public:
    int rows;
    int cols;

    vector<vector<int>> dp;

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if(dp[i][j] != 0) return dp[i][j];

        int currentMax = 1;

        for(auto& dir: dirs)
        {
            int nr = i + dir[0];
            int nc = j + dir[1];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] < matrix[i][j])
            {
                currentMax = max(currentMax, 1 + dfs(matrix, nr, nc));
            }
        }
        dp[i][j] = currentMax;
        return currentMax;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        dp = vector<vector<int>>(rows, vector<int>(cols, 0));

        int currentMax = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                currentMax = max(currentMax, dfs(matrix, i, j));
            }
        }
        return currentMax;
    }
};