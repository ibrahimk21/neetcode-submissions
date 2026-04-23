class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        if(s1.empty()) return true;

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        for(char& c: s1)
        {
            s1Count[c - 'a']++;
        }

        int left = 0, right = s1.size() - 1;
        while(right < s2.size())
        {
            if(left == 0)
            {
                for(int i = left; i <= right; i++)
                {
                    windowCount[s2[i] - 'a']++;
                }
            }
            if(windowCount == s1Count) return true;

            windowCount[s2[left] - 'a']--;
            left++;

            right++;
            if(right == s2.size()) break;
            windowCount[s2[right] - 'a']++;
        }
        return false;
    }
};