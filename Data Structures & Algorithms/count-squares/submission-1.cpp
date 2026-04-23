class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> pointCounts;
    // Also keep a list of all points to iterate through for diagonals
    vector<pair<int, int>> points;

    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        pointCounts[x][y]++;
        points.push_back({x, y});
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int totalSquares = 0;

        // Try every existing point as a diagonal P3
        for (auto& p : points) {
            int x3 = p.first;
            int y3 = p.second;

            // 1. Skip if it's the same point or not a diagonal (side length 0 or not square)
            if (abs(x1 - x3) == 0 || abs(x1 - x3) != abs(y1 - y3)) {
                continue;
            }

            // 2. Check if the other two corners P2(x1, y3) and P4(x3, y1) exist
            if (pointCounts[x1].count(y3) && pointCounts[x3].count(y1)) {
                totalSquares += pointCounts[x1][y3] * pointCounts[x3][y1];
            }
        }

        return totalSquares;
    }
};
