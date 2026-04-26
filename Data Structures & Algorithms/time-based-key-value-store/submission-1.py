class TimeMap:

    def __init__(self):
        self.table = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.table[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.table: 
            return ""
        left, right = 0, len(self.table[key]) - 1
        result = ""
        while left <= right:
            mid = (left +  right) // 2
            if self.table[key][mid][0] == timestamp:
                return self.table[key][mid][1]
            elif self.table[key][mid][0] > timestamp:
                right = mid - 1
            else:
                result = self.table[key][mid][1]
                left = mid + 1
        return result