// https://leetcode.com/problems/grid-game/description/

class Solution
{
public:
    long long gridGame(std::vector<std::vector<int>>& grid)
    {
        auto upper = std::accumulate(std::cbegin(grid[0]), std::cend(grid[0]), 0LL);
        auto lower = 0LL;
        auto res = upper - grid[0][0];

        for (auto i = 0; i < std::size(grid[0]); i++)
        {
            upper -= grid[0][i];
            res = std::min(res, std::max(lower, upper));
            lower += grid[1][i];
        }

        return res;
    }
};