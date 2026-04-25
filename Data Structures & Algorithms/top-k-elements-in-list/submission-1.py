class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        seen = Counter(nums)
        freq = defaultdict(list)
        for num, count in seen.items():
            freq[count].append(num)
        
        result = []
        for i in range(len(nums), 0, -1):
            for n in freq[i]:
                result.append(n)
                if len(result) == k:
                    return result