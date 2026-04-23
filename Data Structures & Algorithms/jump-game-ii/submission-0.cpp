class Solution {
public:
    int jump(vector<int>& nums) {
        // Edge case: If array length is 1, we are already at the end.
        if (nums.size() <= 1) return 0;
        
        int jumps = 0;
        int currentJumpEnd = 0;
        int farthest = 0;
        
        // CRITICAL NOTE: We loop up to nums.size() - 2 (i.e., i < n - 1).
        // Why? Because if we are at the last index, we don't need to jump again.
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // 1. Constantly update the furthest place we can get to
            farthest = max(farthest, i + nums[i]);
            
            // 2. If we have reached the end of the current jump's range...
            if (i == currentJumpEnd) {
                jumps++;             // We are forced to take a jump
                currentJumpEnd = farthest; // The new range is the furthest we found
                
                // Optimization: If the new range already covers the end, we can stop early
                if (currentJumpEnd >= nums.size() - 1) break; 
            }
        }
        
        return jumps;
    }
};