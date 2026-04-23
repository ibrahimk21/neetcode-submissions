class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int first = cost[0];
        int second = cost[1];
        
        if (n < 2) return min(first, second); 

        for (int i = 2; i < n; i++) {
            int current = cost[i] + min(first, second);
            
            first = second;
            second = current;
        }
        return min(first, second);
    }
};