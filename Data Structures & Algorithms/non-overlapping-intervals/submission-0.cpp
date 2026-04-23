class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];   // non-decreasing by end
        });
        int removed = 0, lastEnd = INT_MIN;
        for(vector<int>& interval: intervals)
        {
            if(interval[0] >= lastEnd)
            {
                lastEnd = interval[1];
            }
            else
            {
                removed++;
            }
        }
        return removed;
    }
};
