class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndexReachable = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i <= maxIndexReachable)
            {
                maxIndexReachable = max(maxIndexReachable, i + nums[i]);
            }
            else
            {
                return false;
            }
            if(maxIndexReachable >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};