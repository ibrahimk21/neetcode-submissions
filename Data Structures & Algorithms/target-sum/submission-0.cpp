class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty()) return 0;

        int sum = 0;
        for(int& n: nums) sum += n;

        if(abs(target) > sum) return 0;

        if((target + sum) % 2 == 1) return 0;

        int newTarget = (target + sum) / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(newTarget + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); i++)
        {
            int currentNum = nums[i-1];
            for(int j = 0; j <= newTarget; j++)
            {
                dp[i][j] += dp[i-1][j];
                if(j - currentNum >= 0)
                {
                    dp[i][j] += dp[i-1][j - currentNum];
                }   
            }
        }

        return dp[nums.size()][newTarget];
    }
};