class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_occurrence = {}
        for i, char in enumerate(s):
            last_occurrence[char] = i
        
        partitions = []

        current_boundary = 0
        partition_start = 0

        for i, char in enumerate(s):
            current_boundary = max(current_boundary, last_occurrence[char])

            if i == current_boundary:
                size = i - partition_start + 1
                partitions.append(size)
                partition_start = i + 1
        return partitions