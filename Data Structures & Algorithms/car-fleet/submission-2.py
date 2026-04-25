class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        s = []
        for pos, speed in cars:
            timeToArrival = (target - pos) / speed
            if not s or timeToArrival > s[-1]:
                s.append(timeToArrival)
        return len(s)