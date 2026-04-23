class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // 1. Build Adjacency List
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        // 2. Iterate and Count
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;            // Found a new component
                dfs(i, adj, visited); // Visit the ENTIRE component
            }
        }
        
        return count;
    }
};