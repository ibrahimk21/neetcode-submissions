from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        
        for string in strs:
            hist = [0] * 26
            for char in string:
                hist[ord(char)- ord('a')] += 1
            groups[tuple(hist)].append(string)
        
        return list(groups.values())



