class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_so_far = float("-inf")
        current_sum = 0

        for n in nums:
            current_sum += n

            max_so_far = max(max_so_far, current_sum)

            if current_sum < 0:
                current_sum = 0
        return max_so_far