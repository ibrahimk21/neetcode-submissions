class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = {i: i for i in range(1, len(edges) + 1)}
        rank = {i : 1 for i in range(1, len(edges) + 1)}

        def find(u):
            if u != parent[u]:
                parent[u] = find(parent[u])
            return parent[u]
        
        def union(u, v):
            p1, p2 = find(u), find(v)

            if p1 == p2:
                return False
            
            if rank[p2] > rank[p1]:
                parent[p1] = p2
                rank[p2] += rank[p1]
            else:
                parent[p2] = p1
                rank[p1] += rank[p2]
            return True
        
        for u, v in edges:
            if not union(u, v):
                return [u, v]

