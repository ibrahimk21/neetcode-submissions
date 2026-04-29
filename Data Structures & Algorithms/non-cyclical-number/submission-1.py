class Solution:
    def isHappy(self, n: int) -> bool:
        # Helper function acts like our "node.next"
        def get_next(number):
            total_sum = 0
            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit ** 2
            return total_sum
            
        # Initialize our two pointers
        slow = n
        fast = get_next(n)
        
        # Run the race!
        while fast != 1 and slow != fast:
            slow = get_next(slow)               # Moves 1 step
            fast = get_next(get_next(fast))     # Moves 2 steps
            
        # If fast reached 1, it's a happy number.
        # If they collided at any other number, it's a cycle.
        return fast == 1