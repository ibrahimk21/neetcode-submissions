class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 1. MATH CHECK (The Shortcut)
        // A tree with n nodes MUST have exactly n-1 edges.
        if (edges.size() != n - 1) return false;

        // 2. Build Adjacency List
        // Since it's an undirected graph, add edges both ways.
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 3. BFS for Connectivity
        unordered_set<int> visited;
        queue<int> q;
        
        q.push(0);
        visited.insert(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        // 4. Final Verdict
        // If we visited all 'n' nodes, it's a valid tree.
        return visited.size() == n;
    }
};
