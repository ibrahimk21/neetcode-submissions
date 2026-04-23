class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;
        for(int i = 0 ; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack<double> s;

        for(int i = n-1; i >= 0; i--)
        {
            double timeToArrival = (double)(target - cars[i].first) / cars[i].second;
            if(!s.empty() && timeToArrival <= s.top())
            {
                continue;
            }
            s.push(timeToArrival);
        }
        return s.size();
    }
};