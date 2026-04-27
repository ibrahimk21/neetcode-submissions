class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = Counter(tasks)
        max_heap = [-count for count in counts.values()]
        heapq.heapify(max_heap)

        time = 0

        cooldown_q = deque()

        while max_heap or cooldown_q:
            time += 1

            if max_heap:
                count = heapq.heappop(max_heap) + 1
                if count != 0:
                    cooldown_q.append([count, time + n])
            
            if cooldown_q and cooldown_q[0][1] == time:
                heapq.heappush(max_heap, cooldown_q.popleft()[0])
        return time

