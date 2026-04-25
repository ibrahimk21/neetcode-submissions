class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numbers = set(nums)
        maxLength = 0
        for nums in numbers:
            length = 0
            if nums - 1 in numbers:
                continue
            while nums in numbers:
                length += 1
                nums += 1
            maxLength = max(length, maxLength)
        return maxLength
