class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // dp[i][j] means s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base Case: Empty string matches empty pattern
        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                // Case 1: Pattern is '*'
                if (p[j-1] == '*') {
                    // Option A: Zero occurrences (Treat "x*" as empty)
                    // Look 2 steps back in pattern (j-2)
                    bool zero_count = dp[i][j-2];

                    // Option B: One or more occurrences
                    // Only possible if s[i-1] matches the char before star (p[j-2])
                    bool match_char = (s[i-1] == p[j-2] || p[j-2] == '.');
                    bool one_plus_count = match_char && dp[i-1][j];

                    dp[i][j] = zero_count || one_plus_count;
                }
                
                // Case 2: Pattern is '.' or Normal Character
                else {
                    bool match_char = (s[i-1] == p[j-1] || p[j-1] == '.');
                    
                    if (match_char) {
                        dp[i][j] = dp[i-1][j-1]; // Inherit from diagonal
                    }
                }
            }
        }

        return dp[n][m];
    }
};