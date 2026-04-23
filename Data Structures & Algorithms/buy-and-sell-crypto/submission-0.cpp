class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_buy = prices[0], current_record = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < lowest_buy)
            {
                lowest_buy = prices[i];
                continue;
            }
            if(prices[i] - lowest_buy > current_record)
            {
                current_record = prices[i] - lowest_buy; 
            }
        }
        return current_record;
    }
};