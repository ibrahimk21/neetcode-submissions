class Solution:
    def getSum(self, a: int, b: int) -> int:
        # Mask to get the last 32 bits
        mask = 0xFFFFFFFF
        
        while (b & mask) > 0:
            # 1. Calculate the carry (where both have 1s), then shift left
            carry = (a & b) << 1
            
            # 2. Add 'a' and 'b' without the carry using XOR
            a = a ^ b
            
            # 3. Update 'b' to be the carry for the next iteration
            b = carry
        
        # If 'a' is negative in 32-bit terms, Python needs help 
        # to represent it correctly as a signed integer.
        return (a & mask) if b > 0 else a