class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // 1. Initialize Data Structures
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        
        // Initialize indegree for every unique character to 0
        for (const string& w : words) {
            for (char c : w) {
                indegree[c] = 0;
            }
        }
        
        // 2. Build the Graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            // Edge Case: Prefix Logic ("abc" before "ab" is invalid)
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }
            
            // Find the first difference
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    char source = w1[j];   // comes first
                    char target = w2[j];   // comes after
                    
                    // Add edge source -> target
                    // Note: Check if edge exists to avoid double counting indegrees?
                    // For simplicity, usually we use a set or check manually, 
                    // but standard Topo Sort tolerates duplicate edges if handled carefully.
                    // Ideally, use: unordered_map<char, unordered_set<char>> adj;
                    adj[source].push_back(target);
                    indegree[target]++;
                    
                    break; // Stop after first difference
                }
            }
        }
        
        // 3. Kahn's Algorithm (BFS)
        queue<char> q;
        for (auto& pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            
            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // 4. Cycle Detection
        // If result size != total unique letters, we hit a cycle or stuck nodes
        if (result.size() < indegree.size()) return "";
        
        return result;
    }
};