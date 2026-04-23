class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& currentSize)
    {
        //bound check
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return;
        }

        currentSize++;
        grid[i][j] = 0;

        dfs(grid, i + 1, j, currentSize);
        dfs(grid, i, j + 1, currentSize);
        dfs(grid, i - 1, j, currentSize);
        dfs(grid, i, j - 1, currentSize);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int maxSize = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int currentSize = 0;
                if(grid[i][j] == 1)
                {
                    dfs(grid, i, j, currentSize);
                    maxSize = max(maxSize, currentSize);
                }
            }
        }
        return maxSize;
    }
};