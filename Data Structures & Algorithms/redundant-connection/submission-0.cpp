class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

    // Main Function
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);

        // 1. Initialization: Everyone is their own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // 2. Find Roots
            int rootU = find(u, parent);
            int rootV = find(v, parent);

            // 3. Cycle Check
            if (rootU == rootV) {
                // They are already connected! This edge is the answer.
                return edge; 
            }

            // 4. Union (Merge sets)
            parent[rootU] = rootV;
        }

        return {}; // Should not reach here given problem constraints
    }
};