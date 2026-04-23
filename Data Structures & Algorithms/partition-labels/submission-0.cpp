class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 1. Record the last index of every character
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int size = 0;
        int end = 0;
        
        // 2. Iterate and expand
        for (int i = 0; i < s.size(); i++) {
            size++;
            
            // Push the boundary out if this character appears later
            end = max(end, lastIndex[s[i] - 'a']);
            
            // If we reached the boundary, cut it off
            if (i == end) {
                result.push_back(size);
                size = 0; // Reset size for next partition
            }
        }
        
        return result;
    }
};