class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        bool firstRowZero = false, firstColZero = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        //mark which rows and cols need to be zero
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i == 0 && matrix[i][j] == 0) firstRowZero = true;
                if(j == 0 && matrix[i][j] == 0) firstColZero = true;
                if(i > 0 && j > 0 && matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //change to zeros
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRowZero)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(firstColZero)
        {
            for(int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};