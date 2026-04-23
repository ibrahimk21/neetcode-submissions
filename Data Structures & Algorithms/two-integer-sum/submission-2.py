class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
            seen = {}

            for i, num in enumerate(nums):
                if (target - nums[i]) in seen:
                    return[seen[target - nums[i]] , i]
                seen[nums[i]] = i
