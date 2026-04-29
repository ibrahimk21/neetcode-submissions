class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n

        self.components = n

        def find(n1):
            if n1 != parent[n1]:
                parent[n1] = find(parent[n1])
            return parent[n1]
        
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return 0
            
            if rank[p2] > rank[p1]:
                parent[p1] = p2
                rank[p2] += rank[p1]
            else:
                parent[p2] = p1
                rank[p1] += rank[p2]
            return 1
        for n1, n2 in edges:
            self.components -= union(n1, n2)
        return self.components