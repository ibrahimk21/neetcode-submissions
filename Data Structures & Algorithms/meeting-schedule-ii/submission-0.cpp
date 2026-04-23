/**
 * Definition of Interval:
 * class Interval {
 * public:
 * int start, end;
 * Interval(int start, int end) {
 * this->start = start;
 * this->end = end;
 * }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // 1. Sort by Start Time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // 2. Min-Heap to track End Times of active meetings
        // logic: "What is the earliest time a room becomes free?"
        priority_queue<int, vector<int>, greater<int>> min_heap;

        // Add the first meeting's end time to start
        min_heap.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++) {
            // If the new meeting starts AFTER (or when) the earliest meeting ends...
            if (intervals[i].start >= min_heap.top()) {
                min_heap.pop(); // ...we recycle that room (remove old meeting)
            }
            
            // In both cases (recycling or new room), we push the current meeting's end time.
            min_heap.push(intervals[i].end);
        }

        // The heap size represents the max number of concurrent meetings (rooms)
        return min_heap.size();
    }
};