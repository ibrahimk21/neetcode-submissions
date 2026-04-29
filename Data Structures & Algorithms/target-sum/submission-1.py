class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)

        if abs(target) > total_sum:
            return 0
        
        if (target + total_sum) % 2 == 1:
            return 0
        
        subset_target = (target + total_sum) // 2

        dp = [0] * (subset_target + 1)
        dp[0] = 1
        for n in nums:
            for t in range(subset_target, n - 1, -1):
                dp[t] += dp[t - n]
        return dp[subset_target]