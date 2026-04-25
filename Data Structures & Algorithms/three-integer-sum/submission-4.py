class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []
        nums.sort()
        for i, num in enumerate(nums):
            if i > 0 and num == nums[i - 1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < len(nums) and j < k:
                if nums[j] + nums[k] == -num:
                    output.append([num, nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                elif nums[j] + nums[k] > -num:
                    k -= 1
                else:
                    j += 1
        return output
            
        