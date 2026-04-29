class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        def rob_linear(houses):
            rob2, rob1 = 0,  0
            for n in houses:
                current_max = max(n + rob2, rob1)
                rob2 = rob1
                rob1 = current_max
            return rob1
        return max(rob_linear(nums[:-1]), rob_linear(nums[1:]))