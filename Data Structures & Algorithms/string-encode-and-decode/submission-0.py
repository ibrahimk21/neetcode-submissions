class Solution:

    def encode(self, strs: List[str]) -> str:
        string = []
        for s in strs:
            string.append(str(len(s)))
            string.append('!')
            string.append(s)
        return "".join(string)

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        
        while i < len(s):
            j = i
            while s[j] != '!':
                j += 1

            length = int(s[i:j])
            
            start = j + 1
            end = start + length
            
            res.append(s[start : end])
            
            i = end
            
        return res