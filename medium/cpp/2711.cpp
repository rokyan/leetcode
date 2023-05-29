class Solution
{
public:
    std::vector<std::vector<int>> differenceOfDistinctValues(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::vector<std::vector<int>> res(n, std::vector<int>(m));

        std::unordered_set<int> un;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                un.clear();
                
                auto ii = i - 1;
                auto jj = j - 1;

                while (ii >= 0 && jj >= 0)
                {
                    un.insert(grid[ii][jj]);
                    ii--;
                    jj--;
                }

                res[i][j] = std::size(un);

                un.clear();

                ii = i + 1;
                jj = j + 1;

                while (ii < n && jj < m)
                {
                    un.insert(grid[ii][jj]);
                    ii++;
                    jj++;
                }

                res[i][j] -= std::size(un);

                if (res[i][j] < 0)
                {
                    res[i][j] *= -1;
                }
            }
        }

        return res;
    }
};