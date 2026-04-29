class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        reset = 0
        sold = 0
        held = float("-inf")

        for price in prices:
            held, sold, reset = max(held, reset - price), held + price, max(reset, sold)
         
        return max(sold, reset)