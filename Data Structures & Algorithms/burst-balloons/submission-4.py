class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # Pad the array with 1s
        nums = [1] + nums + [1]
        n = len(nums)
        
        # dp[l][r] represents the max coins we can get 
        # by bursting all balloons STRICTLY BETWEEN l and r
        dp = [[0] * n for _ in range(n)]
        
        # OUTER LOOP: The length of the interval (gap between l and r)
        # We start at length 2 because we need at least 1 balloon between l and r to burst.
        for length in range(2, n):
            
            # MIDDLE LOOP: The left boundary 'l'
            for l in range(n - length):
                # The right boundary 'r' is just 'l' plus the current interval length
                r = l + length
                
                # INNER LOOP: 'i' is the LAST balloon to burst inside the (l, r) interval
                for i in range(l + 1, r):
                    
                    # The coins from bursting 'i' last, plus the pre-calculated left and right islands
                    coins = nums[l] * nums[i] * nums[r]
                    coins += dp[l][i] + dp[i][r]
                    
                    dp[l][r] = max(dp[l][r], coins)
                    
        # The answer is the entire padded array, from index 0 to index n-1
        return dp[0][n - 1]