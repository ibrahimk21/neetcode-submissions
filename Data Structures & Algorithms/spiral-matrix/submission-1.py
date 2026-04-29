class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        
        # Define our four starting walls
        left, right = 0, len(matrix[0]) - 1
        top, bottom = 0, len(matrix) - 1
        
        while left <= right and top <= bottom:
            
            # 1. Walk the TOP row (left to right)
            for i in range(left, right + 1):
                res.append(matrix[top][i])
            # Push the top wall down
            top += 1
            
            # 2. Walk the RIGHT column (top to bottom)
            for i in range(top, bottom + 1):
                res.append(matrix[i][right])
            # Push the right wall left
            right -= 1
            
            # THE TRAP CHECK
            # Did pushing the top or right walls cause them to cross?
            if not (left <= right and top <= bottom):
                break
                
            # 3. Walk the BOTTOM row (right to left)
            for i in range(right, left - 1, -1):
                res.append(matrix[bottom][i])
            # Push the bottom wall up
            bottom -= 1
            
            # 4. Walk the LEFT column (bottom to top)
            for i in range(bottom, top - 1, -1):
                res.append(matrix[i][left])
            # Push the left wall right
            left += 1
            
        return res