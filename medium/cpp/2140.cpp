// https://leetcode.com/problems/solving-questions-with-brainpower/description/

class Solution
{
public:
    long long mostPoints(std::vector<std::vector<int>>& questions)
    {
        const auto n = static_cast<int>(std::size(questions));

        std::vector<long long> dp(n);

        for (auto i = n - 1; i >= 0; i--)
        {
            dp[i] = questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0);

            if (i + 1 < n)
            {
                dp[i] = std::max(dp[i], dp[i + 1]);
            }
        }

        return *std::max_element(std::begin(dp), std::end(dp));
    }
};