class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int top = 0, right = matrix[0].size() - 1, left = 0, bottom = matrix.size() - 1;
        vector<int> result;
        while(top <= bottom && left <= right)
        {
            //walk right
            for(int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            //walk down
            for(int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
                
            }
            right--;
            //walk left
            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //walk up
            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};