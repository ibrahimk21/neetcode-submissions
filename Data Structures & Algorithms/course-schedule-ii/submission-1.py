class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
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
        res = []
        completed_count = 0
        while q:
            curr = q.popleft()
            completed_count += 1
            res.append(curr)

            for nei in adj[curr]:
                in_degree[nei] -= 1
                if in_degree[nei] == 0:
                    q.append(nei)
        
        if completed_count == numCourses:
            return res
        return []