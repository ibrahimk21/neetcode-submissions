class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);
        LIS[0] = 1;
        int result = LIS[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int maxLIS = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    maxLIS = max(maxLIS, LIS[j]);
                }
            }
            LIS[i] = 1 + maxLIS;
            result = max(result, LIS[i]);
        }
        return result;
    }
};

// LIS[i] = if LIS[j] < nums[i] then: 1 + LIS[j]

// LIS[i] = 1 + max{LIS[j]| j < i && nums[j] < nums[i] }