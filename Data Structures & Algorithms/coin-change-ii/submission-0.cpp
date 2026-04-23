class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] = number of ways to make amount i
        // Initialize with 0
        vector<unsigned int> dp(amount + 1, 0); 
        
        dp[0] = 1;

        // OUTER LOOP: Iterate through COINS first
        // This ensures we consider coins one by one, preventing duplicate combinations
        for (int coin : coins) {
            
            // INNER LOOP: Iterate through AMOUNTS
            for (int i = coin; i <= amount; i++) {
                if(i - coin >= 0)
                    dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};