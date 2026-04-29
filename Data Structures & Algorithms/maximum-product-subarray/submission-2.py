class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        currMax = currMin = nums[0]

        for n in nums[1:]:
            currMax, currMin = max(n, currMax * n, currMin * n) , min(n, currMax * n, currMin * n)
            res = max(res, currMax)
        
        return res