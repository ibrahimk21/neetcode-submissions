class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Track which parts of the target we have successfully found
        bool foundX = false;
        bool foundY = false;
        bool foundZ = false;

        for (auto& t : triplets) {
            // 1. The "Poison" Check
            // If any value in the triplet is greater than the target, 
            // this triplet is useless. Skip it.
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            // 2. The "Collection" Check
            // Since we know this triplet is valid (doesn't overshoot),
            // we check if it contributes the exact number we need for any position.
            if (t[0] == target[0]) foundX = true;
            if (t[1] == target[1]) foundY = true;
            if (t[2] == target[2]) foundZ = true;
        }

        // If we found exact matches for all three positions using only valid triplets, we win.
        return foundX && foundY && foundZ;
    }
};