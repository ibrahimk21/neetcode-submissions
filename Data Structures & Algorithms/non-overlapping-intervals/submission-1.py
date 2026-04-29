class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x: x[1])

        removed_count = 0
        current_end = intervals[0][1]

        for i in range(1, len(intervals)):
            interval = intervals[i]
            if interval[0] < current_end:
                removed_count += 1
            else:
                current_end = interval[1]
        
        return removed_count