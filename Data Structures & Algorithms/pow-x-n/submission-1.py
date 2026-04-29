class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Handle the negative power edge case
        if n < 0:
            x = 1 / x
            n = -n
            
        res = 1.0
        
        while n > 0:
            # If the power is odd, multiply the current base into the result
            if n % 2 == 1:
                res *= x
                
            # Square the base and halve the power
            x *= x
            n //= 2
            
        return res