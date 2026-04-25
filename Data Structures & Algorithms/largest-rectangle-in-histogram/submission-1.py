class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = []  # Stores indices
        
        # We append a 0 to force all remaining bars to pop at the end
        heights.append(0)
        
        for i, h in enumerate(heights):
            # THE CHAIN REACTION:
            # If we find a shorter bar, the taller bars on the stack are trapped.
            while stack and heights[stack[-1]] > h:
                # 1. Pop the trapped bar to get our height
                popped_index = stack.pop()
                height = heights[popped_index]
                
                # 2. Calculate the width
                # If stack is empty, it means this popped bar was the shortest one we've seen so far,
                # so it extends all the way back to the very beginning (width = i).
                # Otherwise, it only extends back to the index currently sitting at the top of the stack.
                if not stack:
                    width = i
                else:
                    width = i - stack[-1] - 1
                    
                # 3. Update max area
                max_area = max(max_area, height * width)
                
            # Push the current index onto our increasing stack
            stack.append(i)
            
        # Clean up the array so we don't permanently modify the caller's data
        heights.pop()
        
        return max_area