class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;

        int longest = 0, left = 0;
        unordered_map<char, int> seen;
        
        for(int right = 0; right < s.length(); right++)
        {
            seen[s[right]]++;

            while(seen[s[right]] > 1)
            {
                seen[s[left]]--;
                left++;
            }

            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};