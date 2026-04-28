class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(start_index, current_set):
            res.append(current_set[:])

            for i in range(start_index, len(nums)):
                if i > start_index and nums[i] == nums[i - 1]:
                    continue
                current_set.append(nums[i])
                backtrack(i + 1, current_set)
                current_set.pop()
        backtrack(0, [])
        return res