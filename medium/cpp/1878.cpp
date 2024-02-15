// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

class Solution
{
public:
    std::vector<int> getBiggestThree(std::vector<std::vector<int>>& grid)
    {
        const auto n = static_cast<int>(std::size(grid));
        const auto m = static_cast<int>(std::size(grid.front()));

        std::array<int, 4> di{ 1, 0, -1, 0 };
        std::array<int, 4> dj{ 0, -1, 0, 1 };

        std::set<int, greater<>> un;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                un.insert(grid[i][j]);

                auto d = std::min({ i, n - i - 1, j, m - j - 1 });

                for (auto dd = 1; dd <= d; dd++)
                {
                    auto s = 0;
                    auto ii = i - dd;
                    auto jj = j;

                    for (auto t = 0; t < dd; t++)
                    {
                        s += grid[ii++][jj++];
                    }

                    for (auto t = 0; t < dd; t++)
                    {
                        s += grid[ii++][jj--];
                    }

                    for (auto t = 0; t < dd; t++)
                    {
                        s += grid[ii--][jj--];
                    }

                    for (auto t = 0; t < dd; t++)
                    {
                        s += grid[ii--][jj++];
                    }

                    un.insert(s);
                }
            }
        }

        std::vector<int> res;

        for (auto times = 0; times < 3 && !un.empty(); times++)
        {
            res.push_back(*std::cbegin(un));
            un.erase(std::cbegin(un));
        }

        return res;
    }
};