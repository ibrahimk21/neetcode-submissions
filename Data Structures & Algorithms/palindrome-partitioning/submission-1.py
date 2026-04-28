class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def backtrack(start_index, current_partition):
            if start_index == len(s):
                res.append(current_partition[:])
                return
            
            for i in range(start_index, len(s)):
                if self.isPali(s, start_index, i):
                    current_partition.append(s[start_index: i + 1])
                    backtrack(i + 1, current_partition)
                    current_partition.pop()
        backtrack(0, [])
        return res
    def isPali(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True