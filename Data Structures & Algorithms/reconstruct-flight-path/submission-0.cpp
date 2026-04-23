class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flights;
    vector<string> route;

    void dfs(string airport)
    {
        while(!flights[airport].empty())
        {
            string nextDest = flights[airport].top();
            flights[airport].pop();
            dfs(nextDest);
        }
        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t: tickets)
        {
            flights[t[0]].push(t[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());
        return route;
    }
};