// https://leetcode.com/problems/score-after-flipping-matrix/

class Solution
{
public:
    int matrixScore(std::vector<std::vector<int>>& grid)
    {
        const std::size_t n = std::size(grid);
        const std::size_t m = std::size(grid.front());
        
        for (std::size_t row = 0; row < n; row++)
        {
            if (grid[row][0] == 0)
            {
                for (std::size_t col = 0; col < m; col++)
                {
                    grid[row][col] ^= 1;
                }
            }
        }
        
        for (std::size_t col = 1; col < m; col++)
        {
            int count = 0;
            
            for (std::size_t row = 0; row < n; row++)
            {
                if (grid[row][col] == 1)
                {
                    count++;
                }
            }
            
            if (count <= n / 2)
            {
                for (std::size_t row = 0; row < n; row++)
                {
                    grid[row][col] ^= 1;
                }
            }
        }
        
        std::vector<int> parts(m);
        
        for (int bit = 0; bit < m; bit++)
        {
            parts[bit] = 1 << (m - bit - 1);
        }
        
        int sum = 0;
        
        for (std::size_t row = 0; row < n; row++)
        {
            int cur = 0;
            
            for (std::size_t col = 0; col < m; col++)
            {
                cur += parts[col] * grid[row][col];
            }
            
            sum += cur;
        }
        
        return sum;
    }
};