// https://leetcode.com/problems/equal-sum-grid-partition-i/description/

class Solution
{
public:
    bool canPartitionGrid(const std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        auto sum = 0LL;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                sum += grid[i][j];
            }
        }

        auto curSum = 0LL;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                curSum += grid[i][j];
            }

            if (curSum == sum - curSum)
            {
                return true;
            }
        }

        curSum = 0;

        for (auto j = 0; j < m; j++)
        {
            for (auto i = 0; i < n; i++)
            {
                curSum += grid[i][j];
            }

            if (curSum == sum - curSum)
            {
                return true;
            }
        }

        return false;
    }
};