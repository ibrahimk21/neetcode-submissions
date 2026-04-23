class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> map(128, 0);
        for(char c: t) map[c]++;
        int counter = 0;
        int minLen = INT_MAX;
        int start = 0, left = 0, right = 0;

        while(right < s.size())
        {
            char c = s[right];

            if(map[c] > 0) counter++;
            map[c]--;

            right++;
            while(counter == t.size())
            {
                if(right - left < minLen) 
                {
                    start = left;
                    minLen = right - left;
                }

                char temp = s[left];
                map[temp]++;

                if(map[temp] > 0) counter--;
                
                left++;
            }
        }
        return minLen  == INT_MAX ? "" : s.substr(start, minLen);
    }
};