// https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/

class Solution
{
public:
    long long maxEnergyBoost(const std::vector<int>& energyDrinkA, const std::vector<int>& energyDrinkB)
    {
        const auto n = std::size(energyDrinkA);

        std::vector<std::vector<long long>> dp(2, std::vector<long long>(n));

        for (auto i = 0; i < n; i++)
        {
            dp[0][i] = energyDrinkA[i] + (i > 0 ? dp[0][i - 1] : 0);

            if (i > 1)
            {
                dp[0][i] = std::max(dp[0][i], energyDrinkA[i] + dp[1][i - 2]);
            }

            dp[1][i] = energyDrinkB[i] + (i > 0 ? dp[1][i - 1] : 0);

            if (i > 1)
            {
                dp[1][i] = std::max(dp[1][i], energyDrinkB[i] + dp[0][i - 2]);
            }
        }

        return std::max(dp[0][n - 1], dp[1][n - 1]);
    }
};