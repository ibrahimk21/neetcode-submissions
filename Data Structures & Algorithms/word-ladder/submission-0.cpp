class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Convert vector to Unordered Set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Edge Case: If endWord isn't in the list, we can't reach it.
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        
        // "Visited" logic: We can remove words from the dict to mark them visited
        // This saves space (no separate visited set needed)
        // Note: beginWord might not be in dict, that's fine.
        
        int steps = 1;

        while (!q.empty()) {
            int size = q.size(); // Process one level at a time
            
            while (size--) {
                string currentWord = q.front();
                q.pop();

                if (currentWord == endWord) return steps;

                // TRY CHANGING EVERY LETTER
                // For 'hit': try changing 'h' to a-z, then 'i', then 't'
                for (int i = 0; i < currentWord.length(); i++) {
                    char originalChar = currentWord[i]; // Save original ('h')

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;

                        currentWord[i] = c; // Change to 'ait', 'bit'... 'hot'

                        // Does this new word exist in our dictionary?
                        if (dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord); // Mark as visited by removing!
                        }
                    }
                    currentWord[i] = originalChar; // Undo change for next position
                }
            }
            steps++;
        }

        return 0; // Impossible path
    }
};