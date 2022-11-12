// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution
{
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum)
    {
        const auto n = std::size(rowSum);
        const auto m = std::size(colSum);
        
        std::vector<std::vector<int>> solution(n, std::vector<int>(m));
        
        for (std::size_t i = 0, j = 0; i < n && j < m; )
        {
            const auto val = std::min(rowSum[i], colSum[j]);

            solution[i][j] = val;

            rowSum[i] -= val;
            colSum[j] -= val;

            i += rowSum[i] == 0;
            j += colSum[j] == 0;
        }
        
        return solution;
    }
};