class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []
        nums.sort()
        for i, num in enumerate(nums):
            if i > 0 and num == nums[i - 1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < len(nums) and j < k:
                total = num + nums[j] + nums[k]
                if total == 0:
                    output.append([num, nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                elif total > 0:
                    k -= 1
                else:
                    j += 1
        return output
            
        