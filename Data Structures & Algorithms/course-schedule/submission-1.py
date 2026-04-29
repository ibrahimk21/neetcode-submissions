class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # initialize adj list and in degree array
        adj = {i : [] for i in range(numCourses)}
        in_degree = [0] * numCourses

        # build the graph
        # pair from the question is [course, prerequisite]

        for crs, pre in prerequisites:
            adj[pre].append(crs)
            in_degree[crs] += 1
        
        # find all initial sources
        q = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)
        
        completed_count = 0
        while q:
            curr = q.popleft()
            completed_count += 1

            for nei in adj[curr]:
                in_degree[nei] -= 1
                if in_degree[nei] == 0:
                    q.append(nei)
        
        return completed_count == numCourses
        
