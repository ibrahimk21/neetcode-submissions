class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        right = left = 0
        maxCount = maxLength = 0
        while right < len(s):
            count[s[right]] += 1
            maxCount = max(maxCount, count[s[right]])

            while right - left + 1 - maxCount > k:
                count[s[left]] -= 1
                left += 1
            
            maxLength = max(maxLength, right - left + 1)
            right += 1
        return maxLength

        