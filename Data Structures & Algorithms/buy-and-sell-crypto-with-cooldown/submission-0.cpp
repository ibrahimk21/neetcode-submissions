class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Edge case: If there are no prices, profit is 0
        if (prices.empty()) return 0;

        // Initialize states for Day 0
        
        // 1. Held: We bought the stock. Profit is negative (we spent money).
        int held = -prices[0]; 
        
        // 2. Sold: Impossible to sell on Day 0. 
        // We use INT_MIN (or a very small number) to signify this is invalid initially.
        int sold = 0; 
        
        // 3. Reset: We did nothing. Profit is 0.
        int reset = 0;

        // Iterate starting from Day 1
        for (int i = 0; i < prices.size(); i++) {
            
            // Store previous values because we are updating them simultaneously
            int prev_held = held;
            int prev_sold = sold;
            int prev_reset = reset;

            // Update Held: Either keep holding OR Buy (only possible from Reset)
            held = max(prev_held, prev_reset - prices[i]);

            // Update Sold: Only possible if we Held yesterday and Sell today
            sold = prev_held + prices[i];

            // Update Reset: Either keep Resting OR recover from Sold state
            reset = max(prev_reset, prev_sold);
        }

        //  The best we can do is end up with no stock.
        // We can't end in 'Held' (that means we still have stock and haven't realized profit).
        // It's usually max(sold, reset).
        return max(sold, reset);
    }
};