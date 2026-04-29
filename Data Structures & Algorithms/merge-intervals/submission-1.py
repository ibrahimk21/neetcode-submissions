class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort(key=lambda x: x[0])

        merged = [intervals[0]]

        for i in range(1, len(intervals)):
            last_merged = merged[-1]
            current = intervals[i]

            if current[0] <= last_merged[1]:
                last_merged[1] = max(current[1], last_merged[1])
            else:
                merged.append(current)
        return merged