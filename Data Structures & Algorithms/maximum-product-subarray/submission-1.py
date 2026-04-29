class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        currMax = currMin = nums[0]

        for n in nums[1:]:
            tmp = currMax * n

            currMax = max(n, tmp, currMin * n)
            currMin = min(n, tmp, currMin * n)

            res = max(res, currMax)
        
        return res