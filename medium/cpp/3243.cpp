// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/

class Solution
{
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries)
    {
        std::vector<int> dp(n);

        for (auto i = 1; i < n; i++)
        {
            dp[i] = 1 + dp[i - 1];
        }

        const auto qc = std::size(queries);

        std::vector<int> res(qc);

        std::vector<std::vector<int>> back(n);

        for (auto i = 1; i < n; i++)
        {
            back[i].push_back(i - 1);
        }

        for (auto q = 0; q < qc; q++)
        {
            const auto u = queries[q][0];
            const auto v = queries[q][1];

            back[v].push_back(u);

            for (auto i = v; i < n; i++)
            {
                for (auto j : back[i])
                {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }

            res[q] = dp.back();
        }

        return res;
    }
};