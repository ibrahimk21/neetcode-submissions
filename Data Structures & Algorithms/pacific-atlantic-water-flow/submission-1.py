class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []

        ROWS, COLS = len(heights), len(heights[0])
        pac_q = deque()
        atl_q = deque()
        pac_reachable = set()
        atl_reachable = set()

        for r in range(ROWS):
            for c in range(COLS):
                if r == 0 or c == 0:
                    pac_q.append((r, c))
                    pac_reachable.add((r, c))
                if r == ROWS - 1 or c == COLS - 1:
                    atl_q.append((r, c))
                    atl_reachable.add((r, c))

        def bfs(q, reachable):
            directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
            while q:
                r, c = q.popleft()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (nr < 0 or nc < 0 or nr >= ROWS or nc >= COLS or 
                        heights[nr][nc] < heights[r][c] or (nr, nc) in reachable):
                        continue
                    reachable.add((nr, nc))
                    q.append((nr, nc))
        
        bfs(pac_q, pac_reachable)
        bfs(atl_q, atl_reachable)

        return [list(cell) for cell in pac_reachable & atl_reachable]