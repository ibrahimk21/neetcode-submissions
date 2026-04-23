class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLength = 0;
        for(int n: numSet)
        {
            int length = 0;
            if(numSet.count(n - 1))
            {
                continue;
            }
            else
            {
                while(numSet.count(n))
                {
                    length++;
                    n++;
                }
            }
            if(length > maxLength) maxLength = length;
        }
        return maxLength;
    }
};