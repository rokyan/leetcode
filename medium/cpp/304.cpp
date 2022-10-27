// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
public:
    NumMatrix(std::vector<std::vector<int>>& matrix)
    {
        n = std::size(matrix);
        m = std::size(matrix.front());
        
        build(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = sums[row2][col2];
        
        if (row1 > 0)
        {
            sum -= sums[row1 - 1][col2];
        }
        
        if (col1 > 0)
        {
            sum -= sums[row2][col1 - 1];
        }
        
        if (row1 > 0 && col1 > 0)
        {
            sum += sums[row1 - 1][col1 - 1];
        }
        
        return sum;
    }
    
private:
    void build(const std::vector<std::vector<int>>& matrix)
    {
        sums = matrix;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    sums[i][j] += sums[i - 1][j];
                }
                
                if (j > 0)
                {
                    sums[i][j] += sums[i][j - 1];
                }
                
                if (i > 0 && j > 0)
                {
                    sums[i][j] -= sums[i - 1][j - 1];
                }
            }
        }
    }
    
private:
    std::size_t n;
    std::size_t m;
    
    std::vector<std::vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */