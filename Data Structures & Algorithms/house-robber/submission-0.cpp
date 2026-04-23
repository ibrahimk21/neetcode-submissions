class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_1 = 0;
        int dp_2 = 0;

        for(int n: nums)
        {
            int dp_i = max(dp_1, dp_2 + n);

            dp_2 = dp_1;
            dp_1 = dp_i;
        }

        return dp_1;
    }
};