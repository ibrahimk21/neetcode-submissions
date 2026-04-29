class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # build adj list
        adj = defaultdict(list)
        for u, v, w, in times:
            adj[u].append([v, w])
        
        # priority queue (current_total_time, current_node)
        # we start at node k with time 0
        min_heap = [(0, k)]

        visited = {} # node -> time

        while min_heap:
            w1, n1 = heapq.heappop(min_heap)
            if n1 in visited:
                continue
            
            visited[n1] = w1

            for n2, w2 in adj[n1]:
                if n2 not in visited:
                    heapq.heappush(min_heap, (w1 + w2, n2))
        
        if len(visited) == n:
            return max(visited.values())
        return -1