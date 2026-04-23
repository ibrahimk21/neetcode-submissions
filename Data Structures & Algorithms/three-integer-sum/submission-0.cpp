class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) 
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    int currLeft = nums[left];
                    int currRight = nums[right];

                    while(left < right && nums[left] == currLeft) left++;
                    while(left < right && nums[right] == currRight) right--;
                }
                else if(sum > 0) right--;
                else left++;
            }
        }
        return result;
    }
};