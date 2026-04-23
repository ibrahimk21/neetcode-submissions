class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. Count frequencies
        unordered_map<char, int> counts;
        for (char t : tasks) counts[t]++;
        
        // 2. Max Heap to store frequencies
        priority_queue<int> pq;
        for (auto& pair : counts) {
            pq.push(pair.second);
        }
        
        // 3. Queue for cooling tasks: {remaining_count, time_available}
        queue<pair<int, int>> q;
        
        int time = 0;
        
        // Run until both are empty
        while (!pq.empty() || !q.empty()) {
            time++; // Tick the clock
            
            // Step A: Process Task from Heap
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                
                count--; // Use one instance
                if (count > 0) {
                    // Not done yet, put in cooldown
                    // It becomes available at time + n
                    q.push({count, time + n});
                }
            }
            
            // Step B: Check if anything in Queue is ready to return to Heap
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};