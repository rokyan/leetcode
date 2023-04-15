// https://leetcode.com/problems/check-knight-tour-configuration/description/

class Solution
{
public:
    bool checkValidGrid(std::vector<std::vector<int>>& grid)
    {
        if (grid[0][0] != 0)
        {
            return false;
        }
        
        const auto n = std::size(grid);

        std::vector<pair<int, int>> co(n * n);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                co[grid[i][j]] = {i, j};
            }
        }

        std::vector<std::pair<int, int>> df
        {
            {1, 2}, {2, 1}, {2, -1}, {1, -2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };

        for (auto i = 1; i < n * n; i++)
        {
            const auto p = std::make_pair(co[i].first - co[i - 1].first, co[i].second - co[i - 1].second);

            if (const auto it = std::find(std::begin(df), std::end(df), p); it == std::end(df))
            {
                return false;
            }
        }

        return true;
    }
};