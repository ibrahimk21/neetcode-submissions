class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        ROWS, COLS = len(matrix), len(matrix[0])
        first_col_zero = False
        
        # Phase 1: Mark the boundaries
        for r in range(ROWS):
            # Check if the first column needs to be zeroed
            if matrix[r][0] == 0:
                first_col_zero = True
                
            # Check the rest of the row
            for c in range(1, COLS):
                if matrix[r][c] == 0:
                    # Flag the row and the column
                    matrix[r][0] = 0
                    matrix[0][c] = 0
                    
        # Phase 2: Zero out the inner matrix based on the boundaries
        for r in range(1, ROWS):
            for c in range(1, COLS):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
                    
        # Phase 3: Zero out the boundaries if necessary
        # We must do the row first, so we don't accidentally overwrite matrix[0][0]
        if matrix[0][0] == 0:
            for c in range(COLS):
                matrix[0][c] = 0
                
        if first_col_zero:
            for r in range(ROWS):
                matrix[r][0] = 0
        