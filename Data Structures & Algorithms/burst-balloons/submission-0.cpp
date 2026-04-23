class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Create the padded array (Size n + 2)
        // Indices: 0 to n+1
        vector<int> A(n + 2);
        A[0] = 1;
        A[n + 1] = 1;
        for(int i = 0; i < n; i++) A[i+1] = nums[i];
        
        // 2. DP Table (Size n+2 x n+2)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 3. Iterate by Length of the range (from 1 to n)
        for (int len = 1; len <= n; len++) {
            
            // FIX IS HERE: i must stop at (n - len)
            // This ensures j (which is i + len + 1) never exceeds n + 1
            for (int i = 0; i <= n - len; i++) {
                
                int j = i + len + 1; // The right boundary
                
                // 4. Try every 'k' as the LAST balloon to burst
                for (int k = i + 1; k < j; k++) {
                    
                    int coins = dp[i][k] + dp[k][j] + (A[i] * A[k] * A[j]);
                    
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};