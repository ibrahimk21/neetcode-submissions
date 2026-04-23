class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty()) return;
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        //collect all sources
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        //multi source BFS
        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();
            for(auto& dir: directions)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == INT_MAX)
                {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
