from collections import defaultdict

def isAnagram(str1: str, str2: str) -> bool:
    if len(str1) != len(str2):
        return False
        
    hist1, hist2 = {}, {}
    
    for char1, char2 in zip(str1, str2):
        hist1[char1] = hist1.get(char1, 0) + 1
        hist2[char2] = hist2.get(char2, 0) + 1
        
    return hist1 == hist2

class Solution:
    


    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        
        for string in strs:
            found = False
            for key, value in groups.items():
                if isAnagram(string, key):
                    groups[key].append(string)
                    found = True
                    break
            if not found:
                groups[string].append(string)
        
        return list(groups.values())



