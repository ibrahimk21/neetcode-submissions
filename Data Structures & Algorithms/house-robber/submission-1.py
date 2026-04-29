class Solution:
    def rob(self, nums: List[int]) -> int:
        rob1, rob2 = 0, 0

        for n in nums:
            current_max = max(n + rob2, rob1)
            rob2 = rob1
            rob1 = current_max
        return current_max