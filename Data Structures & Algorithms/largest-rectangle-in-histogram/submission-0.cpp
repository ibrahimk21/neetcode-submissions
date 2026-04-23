class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> s;
        int maxArea = 0;

        for(int i = 0; i <= n; i++)
        {
            int currentHeight = (i == n) ? 0 : heights[i];
            while(!s.empty() && currentHeight < heights[s.top()])
            {
                int height = heights[s.top()];
                s.pop();

                int rightBoundary = i;
                int leftBoundary = s.empty() ? -1 : s.top();

                int width = rightBoundary - leftBoundary - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }
};