class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest = 0
        last_index = len(nums) - 1

        for i, jump_power in enumerate(nums):
            if i > farthest:
                return False
            
            farthest = max(farthest, i + jump_power)

            if farthest >= last_index:
                return True
        return False