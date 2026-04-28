class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        ROWS, COLS = len(grid), len(grid[0])
        num_islands = 0
        def dfs(r, c):
            if r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0:
                return 0
            
            grid[r][c] = 0

            return (1 + dfs(r + 1, c) +
                        dfs(r - 1, c) +
                        dfs(r, c + 1) +
                        dfs(r, c - 1))
        max_size = 0
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    current_area = dfs(r, c)
                    max_size = max(max_size, current_area)
        return max_size