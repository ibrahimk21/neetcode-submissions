class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s or len(t) > len(s):
            return ""

        count_t = {}
        for char in t:
            count_t[char] = count_t.get(char, 0) + 1

        required_chars = len(t) 
        valid_chars = 0         
        window = {}

        res = [-1, -1]
        res_len = float("infinity")

        left = 0
        
        for right in range(len(s)):
            char = s[right]
            window[char] = window.get(char, 0) + 1

            if char in count_t and window[char] <= count_t[char]:
                valid_chars += 1

            while valid_chars == required_chars:
                
                current_window_size = right - left + 1
                if current_window_size < res_len:
                    res = [left, right]
                    res_len = current_window_size

                left_char = s[left]
                window[left_char] -= 1

                if left_char in count_t and window[left_char] < count_t[left_char]:
                    valid_chars -= 1

                left += 1

        l, r = res
        return s[l:r + 1] if res_len != float("infinity") else ""

