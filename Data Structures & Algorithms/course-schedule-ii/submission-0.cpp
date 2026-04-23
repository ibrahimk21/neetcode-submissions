class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> coursesProcessed;
        if(numCourses == 0) return coursesProcessed;
        queue<int> sources;
        vector<int> inDegree(numCourses,  0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(vector<int>& edge: prerequisites)
        {
            inDegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
            {
                sources.push(i);
            }
        }
        if(sources.empty()) return coursesProcessed;
        
        while(!sources.empty())
        {
            int curr = sources.front();
            sources.pop();
            coursesProcessed.push_back(curr);
            for(int neighbor: adj[curr])
            {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)
                {
                    sources.push(neighbor);
                }
            }
        }
        if(coursesProcessed.size() == numCourses)
            return coursesProcessed;
        return {};
    }
};