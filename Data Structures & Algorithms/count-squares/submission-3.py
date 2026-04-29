class CountSquares:

    def __init__(self):
        # A hash map to map (x, y) coordinates to their frequency count
        self.points = Counter()

    def add(self, point: List[int]) -> None:
        # Increment the count for this specific coordinate
        self.points[tuple(point)] += 1

    def count(self, point: List[int]) -> int:
        ans = 0
        qx, qy = point
        
        # Iterate through every unique point we have saved
        for (px, py), pts_count in self.points.items():
            
            # Check if it forms a valid diagonal for an axis-aligned square
            # 1. Horizontal distance must equal vertical distance
            # 2. Must not be the exact same point (distance > 0)
            if abs(qx - px) != abs(qy - py) or qx == px or qy == py:
                continue
            
            # Deduce the missing two corners
            corner1 = (qx, py)
            corner2 = (px, qy)
            
            # If both corners exist in our map, we have a square!
            if corner1 in self.points and corner2 in self.points:
                # Multiply the frequencies together to get the total combinations
                ans += pts_count * self.points[corner1] * self.points[corner2]
                
        return ans
        
