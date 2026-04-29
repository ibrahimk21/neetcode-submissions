"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if not intervals:
            return True
        
        intervals.sort(key=lambda x: x.start)

        current_interval = intervals[0]
        for i in range(1, len(intervals)):
            if current_interval.end > intervals[i].start:
                return False
            current_interval = intervals[i]
        return True