class Solution:
    def checkValidString(self, s: str) -> bool:
        leftMin = 0
        leftMax = 0
        
        for char in s:
            if char == '(':
                leftMin += 1
                leftMax += 1
            elif char == ')':
                leftMin -= 1
                leftMax -= 1
            else: # It is a '*'
                leftMin -= 1  # We pretend it is a ')'
                leftMax += 1  # We pretend it is a '('
                
            # Fatal Flaw: Even our most optimistic path has too many closing brackets
            if leftMax < 0:
                return False
                
            # Course Correction: We cannot have negative open brackets
            if leftMin < 0:
                leftMin = 0
                
        # If we can reach exactly 0 open brackets, the string is valid
        return leftMin == 0
        