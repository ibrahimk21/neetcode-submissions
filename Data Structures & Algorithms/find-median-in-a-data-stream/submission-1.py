class MedianFinder:

    def __init__(self):
        self.small = []
        self.large = []


    def addNum(self, num: int) -> None:
        max_of_small = -heapq.heappushpop(self.small, -num)
        heapq.heappush(self.large, max_of_small)

        if len(self.small) < len(self.large):
            min_of_large = heapq.heappop(self.large)
            heapq.heappush(self.small, -min_of_large)

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2
        