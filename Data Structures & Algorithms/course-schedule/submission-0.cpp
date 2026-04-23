class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 || prerequisites.empty()) return true;

        queue<int> sources;
        vector<int> inDegree(numCourses,  0);
        vector<vector<int>> adj(numCourses, vector<int>());
        int coursesProcessed = 0;
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
        if(sources.empty()) return false;
        
        while(!sources.empty())
        {
            int curr = sources.front();
            sources.pop();
            coursesProcessed++;
            for(int neighbor: adj[curr])
            {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)
                {
                    sources.push(neighbor);
                }
            }
        }
        return coursesProcessed == numCourses;
    }
};