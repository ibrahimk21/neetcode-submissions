class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = []
        # add all stones to max heap
        for stone in stones:
            heapq.heappush(max_heap, -1 * stone)
        
        while len(max_heap) > 1:
            x = heapq.heappop(max_heap)
            y = heapq.heappop(max_heap)
            if x == y: 
                continue
            heapq.heappush(max_heap, x - y)
        return (-1 * max_heap[0]) if len(max_heap) == 1 else 0