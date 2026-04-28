class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return -1

        ROWS, COLS = len(grid), len(grid[0])
        q = deque()
        fresh_count = 0 
        time = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh_count += 1
                if grid[r][c] == 2:
                    q.append((r, c))
        
        directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        while q and fresh_count > 0:
            for _ in range(len(q)):
                r, c = q.popleft()

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc

                    if nr < 0 or nc < 0 or nr >= ROWS or nc >= COLS or grid[nr][nc] != 1:
                        continue
                    
                    grid[nr][nc] = 2
                    fresh_count -= 1
                    q.append((nr, nc))
            time += 1
        return time if not fresh_count else -1
