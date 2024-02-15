// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/

class Solution
{
public:
    int maxTrailingZeros(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));
        const auto m = static_cast<int>(std::size(grid.front()));

        std::vector<std::vector<std::pair<int, int>>> row_max_left(n, std::vector<std::pair<int, int>>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (j > 0)
                {
                    row_max_left[i][j].first += row_max_left[i][j - 1].first;
                    row_max_left[i][j].second += row_max_left[i][j - 1].second;
                }

                row_max_left[i][j].first += get_twos(grid[i][j]);
                row_max_left[i][j].second += get_fives(grid[i][j]);
            }
        }

        std::vector<std::vector<std::pair<int, int>>> row_max_right(n, std::vector<std::pair<int, int>>(m));

        for (auto i = 0; i < n; i++)
        {
            for (auto j = m - 1; j >= 0; j--)
            {
                if (j + 1 < m)
                {
                    row_max_right[i][j].first += row_max_right[i][j + 1].first;
                    row_max_right[i][j].second += row_max_right[i][j + 1].second;
                }

                row_max_right[i][j].first += get_twos(grid[i][j]);
                row_max_right[i][j].second += get_fives(grid[i][j]);
            }
        }

        auto res = 0;

        for (auto j = 0; j < m; j++)
        {
            auto twos = 0;
            auto fives = 0;

            for (auto i = 0; i < n; i++)
            {
                res = std::max(res,
                    std::min(row_max_left[i][j].first + twos, row_max_left[i][j].second + fives));
                res = std::max(res,
                    std::min(row_max_right[i][j].first + twos, row_max_right[i][j].second + fives));
                twos += get_twos(grid[i][j]);
                fives += get_fives(grid[i][j]);
            }

            twos = 0;
            fives = 0;

            for (auto i = n - 1; i >= 0; i--)
            {
                res = std::max(res,
                    std::min(row_max_left[i][j].first + twos, row_max_left[i][j].second + fives));
                res = std::max(res,
                    std::min(row_max_right[i][j].first + twos, row_max_right[i][j].second + fives));
                twos += get_twos(grid[i][j]);
                fives += get_fives(grid[i][j]);                
            }
        }

        return res;
    }

private:
    static int get_twos(int x)
    {
        auto res = 0;

        while (x % 2 == 0)
        {
            res++;
            x /= 2;
        }

        return res;
    }

    static int get_fives(int x)
    {
        auto res = 0;

        while (x % 5 == 0)
        {
            res++;
            x /= 5;
        }

        return res;
    }
};