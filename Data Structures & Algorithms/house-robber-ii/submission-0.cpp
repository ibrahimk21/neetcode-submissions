class Solution {
public:
    int normalRob(vector<int>& nums, int start, int end)
    {
        if(nums.size() == 1) return nums[0];
        int prev2 = 0;
        int prev1 = 0;
        for(int i = start; i <= end; i++)
        {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int firstTry = normalRob(nums, 0, nums.size() - 2);
        int secondTry = normalRob(nums, 1, nums.size() - 1);
        return max(firstTry, secondTry);
    }
};


//dp[i] = max{dp[i-1], nums[i] + dp[i-2]}