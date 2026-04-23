class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;
        
        // We perform Binary Search on nums1.
        // We must constrain 'left' and 'right' to ensure 'j' stays within bounds of nums2.
        
        // 1. i cannot be less than (half - n), otherwise j would be > n (index out of bounds)
        // 2. i cannot be more than 'half', otherwise j would be < 0
        int left = max(0, half - n);
        int right = min(m, half);
        
        while (left <= right) {
            int i = left + (right - left) / 2; // Cut in nums1
            int j = half - i;                  // Cut in nums2
            
            // Handle edges (same as before)
            int A_Left  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int A_Right = (i < m) ? nums1[i]     : INT_MAX;
            
            int B_Left  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int B_Right = (j < n) ? nums2[j]     : INT_MAX;
            
            // Cross Check
            if (A_Left <= B_Right && B_Left <= A_Right) {
                if (total % 2 != 0) {
                    return max(A_Left, B_Left);
                }
                return (max(A_Left, B_Left) + min(A_Right, B_Right)) / 2.0;
            } 
            else if (A_Left > B_Right) {
                // Too far right in nums1
                right = i - 1;
            } 
            else {
                // Too far left in nums1
                left = i + 1;
            }
        }
        
        return 0.0;
    }
};