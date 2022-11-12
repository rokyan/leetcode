// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution
{
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum)
    {
        const std::size_t n = std::size(rowSum);
        const std::size_t m = std::size(colSum);
        
        std::vector<std::vector<int>> solution(n, std::vector<int>(m));
        
        while (true)
        {
            int row_largest = 0;
            
            for (std::size_t row = 1; row < n; row++)
            {
                if (rowSum[row] > rowSum[row_largest])
                {
                    row_largest = row;
                }
            }
            
            if (rowSum[row_largest] == 0)
            {
                break;
            }
            
            int col_largest = 0;
            
            for (std::size_t col = 1; col < m; col++)
            {
                if (colSum[col] > colSum[col_largest])
                {
                    col_largest = col;
                }
            }
            
            if (colSum[col_largest] == 0)
            {
                break;
            }
            
            const auto am = std::min(rowSum[row_largest], colSum[col_largest]);
            
            solution[row_largest][col_largest] += am;
            rowSum[row_largest] -= am;
            colSum[col_largest] -= am;
        }
        
        return solution;
    }
};