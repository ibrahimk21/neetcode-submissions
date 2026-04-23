class Solution {
    // Directions for moving in grid: Up, Down, Left, Right
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min Heap: Stores {time/elevation, r, c}
        // Ordered by smallest time first
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Visited array to avoid cycles
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start at (0, 0)
        // The initial cost is the height of the start block itself.
        // Even if you are there instantly, you can't "swim" until water covers it.
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            // Reached the target? Return the bottleneck time.
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            
            // Explore 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check Bounds and Visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    
                    // THE CORE LOGIC:
                    // To enter (nr, nc), the water must be at least grid[nr][nc].
                    // But we also couldn't have gotten here before 'time'.
                    int newTime = max(time, grid[nr][nc]);
                    
                    pq.push({newTime, nr, nc});
                }
            }
        }
        
        return -1; // Should not reach here
    }
};