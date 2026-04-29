class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # Bouncer: If either string is strictly zero, the answer is zero.
        if "0" in [num1, num2]:
            return "0"

        # Initialize our result array with zeroes
        res = [0] * (len(num1) + len(num2))

        # Sweep backwards through both strings
        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                
                # Convert characters to integers using ASCII values
                digit1 = ord(num1[i]) - ord('0')
                digit2 = ord(num2[j]) - ord('0')
                
                product = digit1 * digit2
                
                # The exact indices where this product belongs
                p1, p2 = i + j, i + j + 1
                
                # Add the product to whatever is ALREADY sitting in the p2 spot
                total = product + res[p2]
                
                # Drop the remainder in p2
                res[p2] = total % 10
                # Carry the tens place over to p1
                res[p1] += total // 10
                
        # Cleanup: Skip any leading zeroes (e.g., if we multiplied 2 * 3, 
        # our size 2 array is [0, 6], we need to skip the 0).
        pointer = 0
        while pointer < len(res) and res[pointer] == 0:
            pointer += 1
            
        # Convert the remaining integers back to a single string
        return "".join(map(str, res[pointer:]))