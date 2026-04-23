class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Standard priority_queue is a Max Heap
        // Stores: {squared_distance, {x, y}}
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y; // Optimization: No sqrt needed
            
            maxHeap.push({dist, point});
            
            // If we have more than K elements, remove the FARTHEST one
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Convert Heap to Vector for the result
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};