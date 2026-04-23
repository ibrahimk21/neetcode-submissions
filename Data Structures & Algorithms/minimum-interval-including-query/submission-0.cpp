class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // 1. Sort Intervals by Start Time
        sort(intervals.begin(), intervals.end());

        // 2. Prepare Queries: Store {value, original_index} so we can sort them
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // 3. Min-Heap: Stores {size, end_time}
        // Smallest size is always on top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(queries.size(), -1);
        int i = 0; // Pointer for intervals

        // 4. Sweep Line
        for (auto& q : sortedQueries) {
            int queryVal = q.first;
            int queryIndex = q.second;

            // A. Add all intervals that have started by now
            while (i < intervals.size() && intervals[i][0] <= queryVal) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int size = end - start + 1;
                pq.push({size, end});
                i++;
            }

            // B. Remove intervals that ended before this query
            // If the interval on top ends before 'queryVal', it can't cover us.
            while (!pq.empty() && pq.top().second < queryVal) {
                pq.pop();
            }

            // C. The top is now the best valid interval
            if (!pq.empty()) {
                result[queryIndex] = pq.top().first;
            }
        }

        return result;
    }
};