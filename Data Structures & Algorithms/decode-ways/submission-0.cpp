class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();
        if (n == 1) return 1;

        vector<int> dp(n, 0);

        dp[0] = 1;

        if (s[1] != '0') {
            dp[1] += dp[0];
        }
        int firstTwo = stoi(s.substr(0, 2));
        if (firstTwo >= 10 && firstTwo <= 26) {
            dp[1] += 1; 
        }

        for (int i = 2; i < n; i++) {
            // Single Digit Step
            if (s[i] != '0') {
                dp[i] += dp[i-1];
            }

            // Double Digit Step
            int twoDigit = stoi(s.substr(i-1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
};