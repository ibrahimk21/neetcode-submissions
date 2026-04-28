class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(current_set):
            if len(current_set) == len(nums):
                res.append(current_set[:])
                return
            
            for i in range(len(nums)):
                if nums[i] in current_set:
                    continue
                
                current_set.append(nums[i])
                backtrack(current_set)
                current_set.pop()
        
        backtrack([])
        return res