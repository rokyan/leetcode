// https://leetcode.com/problems/count-number-of-texts/description/

class Solution
{
private:
    static constexpr auto MOD = 1000000007;

public:
    int countTexts(std::string pressedKeys)
    {
        const std::vector<int> times { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };

        const auto n = static_cast<int>(std::size(pressedKeys));

        std::vector<int> dp(n);
  
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < times[pressedKeys[i] - '0']; j++)
            {
                if (j > i || pressedKeys[i - j] != pressedKeys[i])
                {
                    break;
                }

                if (i == j)
                {
                    dp[i]++;
                    dp[i] %= MOD;
                }
                else
                {
                    dp[i] += dp[i - j - 1];
                    dp[i] %= MOD;
                }
            }
        }

        return dp.back();
    }
};