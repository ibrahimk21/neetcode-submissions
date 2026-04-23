class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores INDICES of potential maximums
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // 1. THE RETIREMENT (Front of Deque)
            // If the person at the front is outside the current window (too old), remove them.
            // Current window is [i - k + 1, ... , i]
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. THE HOSTILE TAKEOVER (Back of Deque)
            // While the current number (nums[i]) is bigger than the guy at the back,
            // kick the guy at the back out. He is useless (smaller AND older).
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. THE RECRUITMENT
            // Add the current index to the list of candidates
            dq.push_back(i);

            // 4. THE REPORT
            // Once our window has reached size k (i >= k - 1), 
            // the front of the deque is ALWAYS the maximum.
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};