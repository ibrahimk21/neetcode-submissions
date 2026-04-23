class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = [1] * len(nums)
        pre = 1
        post = 1

        for i in range(len(nums)):
            output[i] *= pre
            pre *= nums[i]
            output[len(nums) - 1 - i] *= post
            post *= nums[len(nums) - 1 - i]

        return output