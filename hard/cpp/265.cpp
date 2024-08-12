// https://leetcode.com/problems/paint-house-ii/description/

class Solution
{
public:
    int minCostII(std::vector<std::vector<int>>& costs)
    {
        std::vector<int> dp(costs.front());

        for (auto i = 1; i < std::size(costs); i++)
        {
            std::vector<int> ndp(std::size(dp));

            for (auto j = 0; j < std::size(ndp); j++)
            {
                ndp[j] = 1000'000'000;

                for (auto k = 0; k < std::size(ndp); k++)
                {
                    if (k != j)
                    {
                        ndp[j] = std::min(ndp[j], dp[k] + costs[i][j]);
                    }
                }
            }

            dp = std::move(ndp);
        }

        return *std::min_element(std::cbegin(dp), std::cend(dp));
    }
};