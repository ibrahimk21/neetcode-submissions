class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k_target) {
        if (left == right) return nums[left];

        // 1. Random Pivot Selection
        int pivotIndex = left + rand() % (right - left + 1);
        int pivotValue = nums[pivotIndex];

        // 2. 3-Way Partitioning Variables
        int lt = left;      // Less Than pointer
        int gt = right;     // Greater Than pointer
        int i = left;       // Current scanner

        // 3. The Partition Loop
        while (i <= gt) {
            if (nums[i] < pivotValue) {
                swap(nums[i], nums[lt]);
                lt++;
                i++;
            } else if (nums[i] > pivotValue) {
                swap(nums[i], nums[gt]);
                gt--;
                // Do not increment i here, we need to check the swapped value
            } else {
                // nums[i] == pivotValue
                i++;
            }
        }

        // Structure is now:
        // [left ... lt-1]      -> Strictly Smaller
        // [lt ... gt]          -> Equal to Pivot
        // [gt+1 ... right]     -> Strictly Larger

        // 4. Decision Logic
        if (k_target >= lt && k_target <= gt) {
            return pivotValue; // Found it! It's in the block of duplicates.
        } else if (k_target < lt) {
            return quickSelect(nums, left, lt - 1, k_target);
        } else {
            return quickSelect(nums, gt + 1, right, k_target);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};