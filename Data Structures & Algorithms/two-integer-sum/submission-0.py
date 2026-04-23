class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
            indices = {}

            for i, n in enumerate(nums):
                indices[n] = i
            
            for i, n in enumerate(nums):
                difference = target - n
                if difference in indices and indices[difference] != i:
                    return [i, indices[difference]]
            return []