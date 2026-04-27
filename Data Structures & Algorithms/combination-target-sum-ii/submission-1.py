class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def backtrack(start_index, current_set, current_sum):
            if current_sum == target:
                res.append(current_set[:])
                return
            if current_sum > target:
                return
            
            for i in range(start_index, len(candidates)):
                if i > start_index and candidates[i] == candidates[i-1]:
                    continue
                current_set.append(candidates[i])
                backtrack(i + 1, current_set, current_sum + candidates[i])
                current_set.pop()
        backtrack(0, [], 0)
        return res
            
