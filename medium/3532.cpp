// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/

class Solution
{
public:
    std::vector<bool> pathExistenceQueries(
        int n,
        const std::vector<int>& nums,
        int maxDiff,
        const std::vector<std::vector<int>>& queries)
    {
        std::vector<std::pair<int, int>> numsWithPos(n);

        for (auto i = 0; i < n; i++)
        {
            numsWithPos[i] = {nums[i], i};
        }

        std::ranges::sort(numsWithPos);

        std::vector<int> inv(n);

        auto i = 0;

        for (const auto [_, pos] : numsWithPos)
        {
            inv[pos] = i++;
        }

        std::vector<int> longest(n, 1);

        for (auto i = 1; i < n; i++)
        {
            if (numsWithPos[i].first - numsWithPos[i - 1].first <= maxDiff)
            {
                longest[i] += longest[i - 1];
            }
        }

        const auto qc = std::size(queries);
        std::vector<bool> res(qc);

        for (auto q = 0; q < qc; q++)
        {
            auto p1 = inv[queries[q][0]];
            auto p2 = inv[queries[q][1]];

            if (p1 > p2)
            {
                std::swap(p1, p2);
            }

            if (p2 - longest[p2] + 1 <= p1)
            {
                res[q] = true;
            }
        }

        return res;
    }
};