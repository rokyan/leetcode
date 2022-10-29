// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());
        
        std::vector<int> prev(m);
        std::vector<int> cur(m);
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                cur[j] = prev[j];

                if (j > 0 && prev[j - 1] < cur[j])
                {
                    cur[j] = prev[j - 1];
                }

                if (j + 1 < m && prev[j + 1] < cur[j])
                {
                    cur[j] = prev[j + 1];
                }

                cur[j] += matrix[i][j];   
            }
            
            std::swap(cur, prev);
        }
        
        return *std::min_element(std::begin(prev), std::end(prev));
    }
};