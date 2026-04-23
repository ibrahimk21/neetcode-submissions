class Solution {
public:
    bool isLegal(int row, int col ,int rows, int cols, pair<int, int> dir, vector<vector<int>>& heights)
    {
        int newRow = row + dir.first;
        int newCol = col + dir.second;
        if(newRow >= 0 && newRow < rows &&
           newCol >= 0 && newCol < cols &&
           heights[row][col] <= heights[newRow][newCol])
           return true;
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacificReachable(rows, vector(cols, false));
        vector<vector<bool>> atlanticReachable(rows, vector(cols, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        for(int row = 0; row < rows; row++)
        {
            pacificQueue.push({row, 0});
            pacificReachable[row][0] = true;
        }
        for(int col = 0; col < cols; col++)
        {
            pacificQueue.push({0, col});
            pacificReachable[0][col] = true;
        }

        for(int row = 0; row < rows; row++)
        {
            atlanticQueue.push({row, cols-1});
            atlanticReachable[row][cols-1] = true;
        }
        for(int col = 0; col < cols; col++)
        {
            atlanticQueue.push({rows-1, col});
            atlanticReachable[rows-1][col] = true;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pacificQueue.empty())
        {
            pair<int, int> curr = pacificQueue.front();
            pacificQueue.pop();
            for(pair<int, int> dir: directions)
            {
                int newRow = curr.first + dir.first;
                int newCol = curr.second + dir.second;
                if(isLegal(curr.first, curr.second, rows, cols, dir, heights) &&
                  !pacificReachable[newRow][newCol])
                {
                    pacificQueue.push({newRow, newCol});
                    pacificReachable[newRow][newCol] = true;
                }
            }
        }
        while(!atlanticQueue.empty())
        {
            pair<int, int> curr = atlanticQueue.front();
            atlanticQueue.pop();
            for(pair<int, int> dir: directions)
            {
                int newRow = curr.first + dir.first;
                int newCol = curr.second + dir.second;
                if(isLegal(curr.first, curr.second, rows, cols, dir, heights) &&
                  !atlanticReachable[newRow][newCol])
                {
                    atlanticQueue.push({newRow, newCol});
                    atlanticReachable[newRow][newCol] = true;
                }
            }
        }

        vector<vector<int>> result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};