class Solution {
public:
    // We use a member variable so we don't have to pass it in every recursive call
    vector<vector<int>> memo;

    bool checkValidString(string s) {
        int n = s.size();
        // Initialize an N x N table with -1
        // Size is n + 1 because index goes up to n
        // Inner size n + 1 is enough because open count can't exceed string length
        memo.assign(n + 1, vector<int>(n + 1, -1));
        
        return solve(0, 0, s);
    }

    bool solve(int i, int count, string& s) {
        // 1. Base Cases
        if (count < 0) return false; // Optimization: Prune impossible paths early
        if (i == s.size()) return count == 0; // Success only if balanced at the end
        
        // 2. Check Cache
        if (memo[i][count] != -1) {
            return memo[i][count];
        }

        bool result = false;

        // 3. Transitions
        if (s[i] == '(') {
            result = solve(i + 1, count + 1, s);
        } 
        else if (s[i] == ')') {
            result = solve(i + 1, count - 1, s);
        } 
        else { // It is '*'
            // Try all 3 timelines:
            // 1. Treat as '(' -> count + 1
            // 2. Treat as ')' -> count - 1
            // 3. Treat as ''  -> count stays same
            result = solve(i + 1, count + 1, s) || 
                     solve(i + 1, count - 1, s) || 
                     solve(i + 1, count, s);
        }

        // 4. Store and Return
        return memo[i][count] = result;
    }
};