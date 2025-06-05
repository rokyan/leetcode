// https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/description/

#include <ranges>

class Solution
{
public:
    long long maxSum(std::vector<std::vector<int>>& grid, const std::vector<int>& limits, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        auto i = 0;

        for (auto& row : grid)
        {
            std::ranges::sort(row, std::greater<int>{});

            for (auto e : row | std::views::take(limits[i]))
            {
                pq.push(e);

                if (std::size(pq) == k + 1)
                {
                    pq.pop();
                }
            }

            i++;
        }

        auto res = 0LL;

        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};