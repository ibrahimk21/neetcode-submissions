class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build Adjacency List: u -> {v, cost}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        // 2. Min Heap: {cost, node, stops_used}
        // Ordered by cost (cheapest first)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        
        // 3. Optimization Array: stops[i] stores the minimum stops used to reach node i so far.
        // We initialize with INT_MAX.
        vector<int> minStops(n, INT_MAX);
        
        while (!pq.empty()) {
            auto vec = pq.top();
            pq.pop();
            
            int cost = vec[0];
            int u = vec[1];
            int stops = vec[2];
            
            // If we reached destination, this is guaranteed to be the cheapest 
            // valid path because it's a Min Heap.
            if (u == dst) return cost;
            
            // PRUNING:
            // If we have exceeded K stops, this path is dead.
            if (stops > k) continue;
            
            // OPTIMIZATION:
            // If we have reached this node before with FEWER (or equal) stops, 
            // and since we are popping in order of cost (so previous was cheaper or equal),
            // then this current path is strictly worse (More Expensive AND More Stops). 
            // Discard it.
            if (stops >= minStops[u]) continue;
            
            // Update the best stops for this node
            minStops[u] = stops;
            
            // Explore neighbors
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                pq.push({cost + w, v, stops + 1});
            }
        }
        
        return -1;
    }
};