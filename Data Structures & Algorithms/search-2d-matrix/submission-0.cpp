class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // 1. Binary Search for the correct ROW
        int top = 0, bottom = rows - 1;
        int targetRow = -1; // To store the row index if found

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            
            // If target is larger than the last element of this row, it must be further down
            if (target > matrix[mid].back()) {
                top = mid + 1;
            } 
            // If target is smaller than the first element, it must be further up
            else if (target < matrix[mid][0]) {
                bottom = mid - 1;
            } 
            // Otherwise, target is within the range of this row!
            else {
                targetRow = mid;
                break;
            }
        }

        // If we didn't find a valid row (target is smaller than first element or bigger than last)
        if (targetRow == -1) return false;

        // 2. Binary Search within that ROW
        int l = 0, r = cols - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[targetRow][mid] == target) return true;
            if (matrix[targetRow][mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return false;
    }
};