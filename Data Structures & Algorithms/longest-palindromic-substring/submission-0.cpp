class Solution {
public:
    int expandAroundCenter(string& s, int left, int right) {
        // Expand as long as bounds are valid and chars match
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length of the valid palindrome
        // Note: left and right are now one step TOO FAR (mismatch or out of bounds)
        // Length formula: (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // Case 1: Odd length (center is i)
            // e.g., "aba" -> center 'b'
            int len1 = expandAroundCenter(s, i, i);

            // Case 2: Even length (center is i, i+1)
            // e.g., "abba" -> center 'bb'
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);

            // If we found a longer palindrome, update start index
            if (len > maxLen) {
                maxLen = len;
                // Math to find start index based on length and center
                // Example: Center i=2, Len=5. Start = 2 - (4)/2 = 0
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};