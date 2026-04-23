class Solution {
public:
    void backtrack(vector<int>& nums, int start,  vector<int>& current, vector<vector<int>>& result)
    {
        result.push_back(current);

        for(int i = start; i < nums.size(); i++)
        {
            //add the current number
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);

            //dont add the current number
            current.pop_back();
        }
    }  
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};