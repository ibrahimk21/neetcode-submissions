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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // 1. Edge Case
        if (intervals.empty()) return true;

        // 2. Sort by Start Time
        // We need a custom comparator (lambda) because 'Interval' is a custom object.
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // 3. Iterate and Check for Overlaps
        for (int i = 0; i < intervals.size() - 1; i++) {
            // Check if current meeting ends AFTER the next one starts
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }

        return true;
    }
};