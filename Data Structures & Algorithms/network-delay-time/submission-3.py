class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # build adj list
        adj = defaultdict(list)
        for u, v, w, in times:
            adj[u].append([v, w])
        
        distance = [float("inf")] * (n + 1)

        distance[k] = 0

        min_heap = [(0, k)]

        while min_heap:
            current_time, u = heapq.heappop(min_heap)

            if current_time > distance[u]:
                continue
            
            for v, weight in adj[u]:
                time_through_u = current_time + weight
                if time_through_u < distance[v]:
                    distance[v] = time_through_u
                    heapq.heappush(min_heap, (distance[v], v))
        
        max_time = max(distance[1:])
        return max_time if max_time != float("inf") else -1