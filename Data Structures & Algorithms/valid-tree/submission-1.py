class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        
        adj = {i : [] for i in range(n)}
        for n1, n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)
        
        visited = set()

        def dfs(curr, prev):
            if curr in visited:
                return False
            
            visited.add(curr)
            
            for nei in adj[curr]:
                if nei == prev:
                    continue
                
                if not dfs(nei, curr):
                    return False
            return True
        
        return dfs(0, -1) and len(visited) == n