"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x: x.start)

        free_rooms = []
        heapq.heappush(free_rooms, intervals[0].end)

        for i in range(1, len(intervals)):
            current_meeting = intervals[i]
            earliest_end_time = free_rooms[0]

            if current_meeting.start >= earliest_end_time:
                heapq.heappop(free_rooms)
            
            heapq.heappush(free_rooms, current_meeting.end)
        return len(free_rooms)