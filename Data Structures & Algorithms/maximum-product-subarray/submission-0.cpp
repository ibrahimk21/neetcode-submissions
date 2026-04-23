class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int prevMax = currMax;
            int prevMin = currMin;

            currMax = max({nums[i], prevMax*nums[i], prevMin*nums[i]});
            currMin = min({nums[i], prevMax*nums[i], prevMin*nums[i]});

            result = max(result, currMax);
        }
        return result;
    }
};

//max[i] = max(nums[i], max[i-1]*nums[i], min[i-1]*nums[i])
//min[i] = min(nums[i], max[i-1]*nums[i], min[i-1]*nums[i])
