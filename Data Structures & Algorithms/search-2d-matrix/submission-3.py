class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # search fo the correct row
        top, bottom = 0, len(matrix) - 1
        targetRow = -1
        while top <= bottom:
            mid = (top + bottom) // 2
            if target > matrix[mid][-1]:
                top = mid + 1
            elif target < matrix[mid][0]:
                bottom = mid - 1
            else:
                targetRow = mid
                break
        if targetRow == -1:
            return False
        
        # search for target within that row
        left, right = 0, len(matrix[targetRow]) - 1
        while left <= right:
            mid = (left + right) // 2
            if target == matrix[targetRow][mid]:
                return True
            elif target > matrix[targetRow][mid]:
                left = mid + 1
            else:
                 right = mid -1
        return False
