class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build Adjacency List: source -> {target, weight}
        // Using n + 1 because nodes are labeled 1 to n
        vector<vector<pair<int, int>>> graph(n + 1);
        for(const auto& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // 2. Distances Array (Initialize to Infinity)
        vector<int> dist(n + 1, INT_MAX);
        
        // 3. Min Heap: {accumulated_time, node_index}
        // "greater" makes it a Min Heap (smallest time on top)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Start at node k with time 0
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()) {
            int time = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Optimization: If we found a faster way to 'u' already, skip this stale entry
            if (time > dist[u]) continue;
            
            // Check neighbors
            for(auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                // Relaxation Step: Can we reach v faster through u?
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // 4. Find the max time in the dist array
        int maxWait = 0;
        for(int i = 1; i <= n; i++) {
            // If any node is still INT_MAX, it's unreachable
            if (dist[i] == INT_MAX) return -1;
            maxWait = max(maxWait, dist[i]);
        }
        
        return maxWait;
    }
};