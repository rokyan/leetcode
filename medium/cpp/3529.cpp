// https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description/

class Solution
{
public:
    int countCells(const std::vector<std::vector<char>>& grid, const std::string& pattern)
    {
        const int n = std::size(grid);
        const auto m = std::size(grid.front());

        std::string horizontal;
        horizontal.reserve(n * m);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                horizontal.push_back(grid[i][j]);
            }
        }

        std::string vertical;
        vertical.reserve(n * m);

        for (auto j = 0; j < m; j++)
        {
            for (auto i = 0; i < n; i++)
            {
                vertical.push_back(grid[i][j]);
            }
        }

        std::vector<std::vector<char>> probe(n, std::vector<char>(m));

        const auto prefHorizontal = calcPref(horizontal, pattern);

        for (auto i = 0, last = 0; i < n * m; i++)
        {
            const auto value = prefHorizontal[i + std::size(pattern) + 1];

            if (value == std::size(pattern))
            {
                for (auto j = std::max<int>(last, i - std::size(pattern) + 1); j <= i; j++)
                {
                    probe[j / m][j % m]++;
                }

                last = i + 1;
            }
        }

        const auto prefVertical = calcPref(vertical, pattern);

        auto res = 0;

        for (auto i = 0, last = 0; i < n * m; i++)
        {
            const auto value = prefVertical[i + std::size(pattern) + 1];

            if (value == std::size(pattern))
            {
                for (auto j = std::max<int>(last, i - std::size(pattern) + 1); j <= i; j++)
                {
                    if (probe[j % n][j / n] == 1)
                    {
                        res++;
                    }
                }

                last = i + 1;
            }
        }

        return res;
    }

private:
    std::vector<int> calcPref(const std::string& s, const std::string& pattern)
    {
        const auto conc = pattern + "#" + s;
        const auto n = std::size(conc);

        std::vector<int> pref(n);

        for (auto i = 1; i < n; i++)
        {
            auto j = pref[i - 1];

            while (j > 0 && conc[i] != conc[j])
            {
                j = pref[j - 1];
            }

		    if (conc[i] == conc[j])
            {
                j++;
            }

    		pref[i] = j;
        }

        return pref;
    }
};