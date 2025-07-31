// https://leetcode.com/problems/number-of-black-blocks/description/

class Solution
{
public:
    std::vector<long long> countBlackBlocks(int m, int n, std::vector<std::vector<int>>& coord)
    {
        std::ranges::sort(coord);

        const auto total = std::size(coord);

        std::set<std::vector<int>> probe(std::cbegin(coord), std::cend(coord));

        std::vector<long long> res(5);

        for (auto i = 0; i < total; i++)
        {
            if (coord[i][0] == m - 1)
            {
                continue;
            }

            if (coord[i][1] < n - 1)
            {
                auto cnt = 1
                    + probe.count({coord[i][0], coord[i][1] + 1})
                    + probe.count({coord[i][0] + 1, coord[i][1]})
                    + probe.count({coord[i][0] + 1, coord[i][1] + 1});

                res[cnt]++;
            }

            if (coord[i][1] > 0 && probe.count({coord[i][0], coord[i][1] - 1}) == 0)
            {
                auto cnt = 1
                    + probe.count({coord[i][0] + 1, coord[i][1]})
                    + probe.count({coord[i][0] + 1, coord[i][1] - 1});

                res[cnt]++;                
            }

            if (coord[i][0] > 0 && coord[i][1] < n - 1
                && probe.count({coord[i][0] - 1, coord[i][1]}) == 0
                && probe.count({coord[i][0] - 1, coord[i][1] + 1}) == 0)
            {
                auto cnt = 1
                    + probe.count({coord[i][0], coord[i][1] + 1});

                res[cnt]++;
            }

            if (coord[i][0] > 0 && coord[i][1] > 0
                && probe.count({coord[i][0] - 1, coord[i][1]}) == 0
                && probe.count({coord[i][0] - 1, coord[i][1] - 1}) == 0
                && probe.count({coord[i][0], coord[i][1] - 1}) == 0)
            {
                auto cnt = 1;

                res[cnt]++;
            }
        }

        res[0] = 1LL * (m - 1) * (n - 1);

        for (auto taken = 1; taken <= 4; taken++)
        {
            res[0] -= res[taken];
        }

        return res;
    }
};