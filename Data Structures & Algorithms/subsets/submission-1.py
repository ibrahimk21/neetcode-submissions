class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(start_index, current_set):
            res.append(current_set[:])

            for i in range(start_index, len(nums)):
                current_set.append(nums[i])
                backtrack(i + 1, current_set)
                current_set.pop()
        backtrack(0, [])
        return res