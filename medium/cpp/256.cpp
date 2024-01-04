// https://leetcode.com/problems/paint-house/description/

class Solution
{
public:
    int minCost(std::vector<std::vector<int>>& costs)
    {
        std::vector<int> dp(costs.front());

        for (auto i = 1; i < std::size(costs); i++)
        {
            std::vector<int> ndp(3, -1);

            for (auto j = 0; j < 3; j++)
            {
                for (auto k = 0; k < 3; k++)
                {
                    if (k != j)
                    {
                        const auto c = costs[i][j] + dp[k];
                        ndp[j] = ndp[j] == -1 ? c : std::min(c, ndp[j]);
                    }
                }
            }

            dp = std::move(ndp);
        }

        return *std::min_element(std::cbegin(dp), std::cend(dp));
    }
};