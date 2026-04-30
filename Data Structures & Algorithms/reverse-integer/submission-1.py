class Solution:
    def reverse(self, x: int) -> int:
        # Define 32-bit signed integer boundaries
        MIN_INT, MAX_INT = -2**31, 2**31 - 1
        
        # Handle the sign
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        res = 0
        while x != 0:
            # Pop the last digit
            digit = x % 10
            x //= 10
            
            # Check for overflow before we update res
            # If (res * 10 + digit) would exceed MAX_INT, return 0
            if res > (MAX_INT - digit) // 10:
                return 0
            
            # Push the digit to the result
            res = (res * 10) + digit
            
        return res * sign