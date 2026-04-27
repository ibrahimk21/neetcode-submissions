class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        max_heap = []
        for point in points:
            heapq.heappush(max_heap, (-(point[0] * point[0] + point[1] * point[1]), point))
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        
        return [point for dist, point in max_heap]
