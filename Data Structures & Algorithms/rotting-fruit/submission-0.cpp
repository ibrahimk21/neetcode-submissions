class Solution {
public:
    vector<pair<int, int>> get_orange_neighbors(vector<vector<int>>& grid,
                                                int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> result;
        for (auto& dir : directions) {
            if (!(r + dir.first < 0 || r + dir.first >= rows ||
                  c + dir.second < 0 || c + dir.second >= cols ||
                  grid[r + dir.first][c + dir.second] == 0 ||
                  grid[r + dir.first][c + dir.second] == 2))
                result.push_back({r + dir.first, c + dir.second});
        }
        return result;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int old_size = 0, new_size = 0, minutes = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    old_size++;
                }
            }
        }
        while (!q.empty()) {
            while (old_size > 0) {
                pair<int, int> head = q.front();
                q.pop();
                vector<pair<int, int>> neighbors =
                    get_orange_neighbors(grid, head.first, head.second);
                new_size += neighbors.size();
                for (auto& neighbor : neighbors) {
                    q.push(neighbor);
                    grid[neighbor.first][neighbor.second] = 2;
                }
                old_size--;
            }

            if (new_size > 0) 
            {
                minutes++;
            }

            old_size = new_size;
            new_size = 0;
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                return -1;
            }
        }
        return minutes;
    }
};