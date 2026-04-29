class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)

        if total_sum % 2 == 1:
            return False

        target = total_sum // 2

        dp = set([0])

        for n in nums:
            next_dp = set()
            for t in dp:
                if t + n == target:
                    return True
                if t + n < target:
                    next_dp.add(t + n)
                next_dp.add(t)
            dp = next_dp
        return False