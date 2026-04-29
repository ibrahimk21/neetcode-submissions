class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        # dp[i][j] means s[:i] matches p[:j]
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        
        # Base Case: Two empty strings match
        dp[0][0] = True
        
        # Base Case: Handle patterns like a*, a*b*, a*b*c* matching empty string s
        for j in range(2, n + 1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-2]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Case 1: The characters match or it's a dot
                if p[j-1] == '.' or p[j-1] == s[i-1]:
                    dp[i][j] = dp[i-1][j-1]
                
                # Case 2: We hit a star
                elif p[j-1] == '*':
                    # Choice A: Zero occurrences of the character before the star
                    dp[i][j] = dp[i][j-2]
                    
                    # Choice B: Use the star (only if character matches)
                    preceding_char = p[j-2]
                    if preceding_char == '.' or preceding_char == s[i-1]:
                        dp[i][j] = dp[i][j] or dp[i-1][j]
                        
        return dp[m][n]