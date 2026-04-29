class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        memo = {}

        def dfs(l, r):
            if l > r - 2:
                return 0

            if (l, r) in memo:
                return memo[(l, r)]
            
            max_coins = 0

            for i in range(l + 1, r):
                coins = nums[l] * nums[i] * nums[r]
                coins += dfs(l, i)  + dfs(i, r)
                max_coins = max(max_coins, coins)
            
            memo[(l, r)] = max_coins
            return max_coins
        return dfs(0, len(nums) - 1)