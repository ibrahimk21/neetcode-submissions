class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n

        self.components = n

        def find(n1):
            # SWEEP 1: Find the ultimate boss (the root)
            root = n1
            while root != parent[root]:
                root = parent[root]
                
            # SWEEP 2: Go back down the chain and update everyone 
            curr = n1
            while curr != root:
                # We must save the next node before we overwrite the pointer!
                next_node = parent[curr]
                
                # Point directly to the ultimate boss we found in Sweep 1
                parent[curr] = root
                
                # Move up the ladder to repeat the process
                curr = next_node
                
            return root
        
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