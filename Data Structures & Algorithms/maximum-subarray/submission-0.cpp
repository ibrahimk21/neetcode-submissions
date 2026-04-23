class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int maxSub = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int next = max(prev + nums[i], nums[i]);
            prev = next;

            maxSub = max(maxSub, prev);
        }
        return maxSub;
    }
};


// dp[i] = maximum sum of subbarray until index i
// dp[i] = max(dp[i-1] + nums[i], nums[i])