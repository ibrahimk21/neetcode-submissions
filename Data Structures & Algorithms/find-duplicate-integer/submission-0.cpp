class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Intersection
        int slow = 0;
        int fast = 0;
        
        do {
            slow = nums[slow];           // Move 1 step
            fast = nums[nums[fast]];     // Move 2 steps
        } while (slow != fast);

        // Phase 2: Find Entrance
        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];    // Move 1 step
            slow2 = nums[slow2];  // Move 1 step
        }
        
        return slow;
    }
};