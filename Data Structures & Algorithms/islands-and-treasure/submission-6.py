class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return
        ROWS, COLS= len(grid), len(grid[0])
        visited = set()
        q = deque()

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visited.add((r, c))
        
        directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        while q:
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if (nr < 0 or nc < 0 or nr >= ROWS or nc >= COLS or 
                    grid[nr][nc] == -1 or (nr, nc) in visited):
                   continue

                visited.add((nr, nc))
                grid[nr][nc] = grid[r][c] + 1
                q.append((nr, nc))
            