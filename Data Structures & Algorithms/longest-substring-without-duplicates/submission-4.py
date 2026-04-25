class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = defaultdict(int)
        left = right = maxLength = 0
        while right < len(s):
            seen[s[right]] += 1
            while seen[s[right]] > 1:
                seen[s[left]] -= 1
                left += 1
            maxLength = max(maxLength, right - left + 1)
            right += 1
        return maxLength