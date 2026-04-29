class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)

        if total_sum % 2 == 1:
            return False

        target = total_sum // 2

        dp = [False] * (target + 1)
        dp[0] = True
        for n in nums:
            for t in range(target, n - 1,  -1):
                if dp[t - n]: 
                    dp[t] = True
            if dp[target]:
                return True
        return dp[target]