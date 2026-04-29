class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        m, n = len(matrix), len(matrix[0])
        # Memoization table
        memo = {}

        def dfs(r, c):
            # If we already calculated this cell, return it immediately
            if (r, c) in memo:
                return memo[(r, c)]
            
            res = 1 # Every cell is a path of at least 1
            
            # Check all 4 neighbors
            for dr, dc in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nr, nc = r + dr, c + dc
                
                # Bouncer: Stay in bounds AND neighbor must be strictly greater
                if (0 <= nr < m and 0 <= nc < n and 
                    matrix[nr][nc] > matrix[r][c]):
                    
                    res = max(res, 1 + dfs(nr, nc))
            
            # Save the result in our memo table
            memo[(r, c)] = res
            return res

        # We must try starting from EVERY cell in the grid
        max_path = 0
        for r in range(m):
            for c in range(n):
                max_path = max(max_path, dfs(r, c))
                
        return max_path
        