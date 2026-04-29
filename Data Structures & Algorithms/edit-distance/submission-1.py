class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        
        # Create the grid
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Initialize the base cases (converting to/from empty strings)
        for i in range(m + 1):
            dp[i][0] = i  # Cost of deleting 'i' characters from word1
        for j in range(n + 1):
            dp[0][j] = j  # Cost of inserting 'j' characters into word1
            
        # Fill the grid
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                
                # Characters match: No extra cost, take the diagonal
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                    
                # Characters mismatch: Find the cheapest operation and add 1
                else:
                    insert_cost = dp[i][j - 1]
                    delete_cost = dp[i - 1][j]
                    replace_cost = dp[i - 1][j - 1]
                    
                    dp[i][j] = 1 + min(insert_cost, delete_cost, replace_cost)
                    
        # The bottom-right cell is the final answer for the full strings
        return dp[m][n]
        