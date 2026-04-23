class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0; // Base case
        
        for(int i = 1; i <= n; i++) {
            // "My bits" = "Bits of half of me" + "My last bit"
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};