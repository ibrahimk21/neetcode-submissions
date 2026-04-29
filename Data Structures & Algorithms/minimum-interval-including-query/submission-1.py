class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort(key=lambda x: x[0])
        
        # Sort queries while remembering their original index
        # We store tuples of (query_value, original_index)
        sorted_queries = sorted([(q, i) for i, q in enumerate(queries)])
        
        # Initialize our result array with -1
        res = [-1] * len(queries)
        
        min_heap = []
        i = 0
        n = len(intervals)
        
        for query_val, original_idx in sorted_queries:
            # Step 1: The Intake
            # Add all intervals that have started by the time this query happens
            while i < n and intervals[i][0] <= query_val:
                start, end = intervals[i]
                size = end - start + 1
                heapq.heappush(min_heap, (size, end))
                i += 1
                
            # Step 2: The Garbage Collection (Lazy Deletion)
            # Remove intervals from the top of the heap if they have already ended
            while min_heap and min_heap[0][1] < query_val:
                heapq.heappop(min_heap)
                
            # Step 3: Record the Answer
            # The top of the heap is guaranteed to be the smallest valid interval
            if min_heap:
                res[original_idx] = min_heap[0][0]
                
        return res