class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currTank = 0;
        int startStation = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if(currTank < 0)
            {
                startStation = i + 1;
                currTank = 0;
            }
        }
        if(totalTank >= 0) return startStation;
        return -1;
    }
};