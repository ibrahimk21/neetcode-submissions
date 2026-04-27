class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        max_heap = [-x for x in nums]
        heapq.heapify(max_heap)

        res = 0
        for _ in range(k):
            res = heapq.heappop(max_heap)
        return -res