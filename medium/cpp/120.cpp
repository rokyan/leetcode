// https://leetcode.com/problems/triangle/

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle)
    {
        const auto n = std::size(triangle);
        
        if (n == 1)
        {
            return triangle[0][0];
        }
        
        std::vector<int> dp_cur(n);
        std::vector<int> dp_prev(n);
        
        dp_prev[0] = triangle[0][0];
        
        for (std::size_t row_idx = 1; row_idx < n; row_idx++)
        {
            for (std::size_t j = 0; j < std::size(triangle[row_idx]); j++)
            {
                dp_cur[j] = triangle[row_idx][j];
                
                if (j + 1 == std::size(triangle[row_idx]))
                {
                    dp_cur[j] += dp_prev[j - 1];
                }
                else if (j == 0)
                {
                    dp_cur[j] += dp_prev[j];
                }
                else
                {
                    dp_cur[j] += std::min(dp_prev[j], dp_prev[j - 1]);
                }
            }
           
            dp_prev = dp_cur;
        }
        
        return *std::min_element(std::begin(dp_cur), std::end(dp_cur));
    }
};