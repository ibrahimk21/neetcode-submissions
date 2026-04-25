class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowestBuy, maxProfit = prices[0], 0
        i = 1
        while i < len(prices):
            if prices[i] < lowestBuy:
                lowestBuy = prices[i]
                continue
            if prices[i] - lowestBuy > maxProfit:
                maxProfit = prices[i] - lowestBuy
            i += 1
        return maxProfit