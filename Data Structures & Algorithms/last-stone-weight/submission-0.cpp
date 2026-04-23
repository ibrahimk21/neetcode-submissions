class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // C++ priority_queue is a Max Heap by default
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // The heaviest
            int x = pq.top(); pq.pop(); // The second heaviest
            
            if (x != y) {
                pq.push(y - x); // Push the remainder back
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};