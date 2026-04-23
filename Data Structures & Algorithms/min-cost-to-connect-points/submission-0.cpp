class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // min_dist[i] stores the shortest distance from node i to the MST we are building
        vector<int> min_dist(n, INT_MAX);
        vector<bool> in_mst(n, false);
        
        // Start from node 0
        min_dist[0] = 0;
        int total_cost = 0;
        int edges_connected = 0;
        
        while (edges_connected < n) {
            // 1. Find the node with the smallest distance that is NOT in the MST yet
            int curr_node = -1;
            int curr_min_edge = INT_MAX;
            
            for (int i = 0; i < n; i++) {
                if (!in_mst[i] && min_dist[i] < curr_min_edge) {
                    curr_min_edge = min_dist[i];
                    curr_node = i;
                }
            }
            
            // 2. Add this node to the MST
            in_mst[curr_node] = true;
            total_cost += curr_min_edge;
            edges_connected++;
            
            // 3. Update the distances for the neighbors (all other nodes)
            for (int next_node = 0; next_node < n; next_node++) {
                if (!in_mst[next_node]) {
                    int dist = abs(points[curr_node][0] - points[next_node][0]) + 
                               abs(points[curr_node][1] - points[next_node][1]);
                    
                    // If connecting from 'curr_node' is cheaper than whatever option 
                    // 'next_node' had before, update it.
                    if (dist < min_dist[next_node]) {
                        min_dist[next_node] = dist;
                    }
                }
            }
        }
        
        return total_cost;
    }
};