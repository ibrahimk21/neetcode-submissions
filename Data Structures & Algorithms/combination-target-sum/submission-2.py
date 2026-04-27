class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(start_index, current_set):
            s = sum(current_set)
            if s == target:
                res.append(current_set[:])
                return
            elif s > target:
                return
            
            for i in range(start_index, len(nums)):
                current_set.append(nums[i])
                backtrack(i, current_set)
                current_set.pop()
        backtrack(0, [])
        return res