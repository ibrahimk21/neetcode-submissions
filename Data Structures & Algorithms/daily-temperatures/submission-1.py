class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s = []
        output = [0] * len(temperatures)
        for i in range(len(temperatures)):

            while s and temperatures[i] > temperatures[s[-1]]:
                output[s[-1]] = i - s[-1]
                s.pop()
            
            s.append(i)
        return output
