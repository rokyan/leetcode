// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

class Solution
{
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs)
    {
        std::sort(std::begin(pairs), std::end(pairs), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        std::vector<int> dp(std::size(pairs));

        for (auto i = 0; i < std::size(pairs); i++)
        {
            dp[i] = 1;

            for (auto j = 0; j < i; j++)
            {
                if (pairs[j][1] >= pairs[i][0])
                {
                    break;
                }

                dp[i] = std::max(dp[i], 1 + dp[j]);
            }
        }

        return *std::max_element(std::begin(dp), std::end(dp));
    }
};