// https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/

class Solution
{
public:
    int removeAlmostEqualCharacters(std::string word)
    {
        const auto n = std::size(word);
        std::vector<std::vector<int>> dp(n, std::vector<int>(26, 2 * n));

        for (auto i = 0; i < n; i++)
        {
            const auto c = word[i] - 'a';

            for (auto nc = 0; nc < 26; nc++)
            {
                auto cost = nc != c;

                if (i > 0)
                {
                    for (auto pc = 0; pc < 26; pc++)
                    {
                        if (std::abs(pc - nc) <= 1)
                        {
                            continue;
                        }

                        dp[i][nc] = std::min<int>(dp[i][nc], cost + dp[i - 1][pc]);
                    }
                }
                else
                {
                    dp[i][nc] = std::min<int>(dp[i][nc], cost);
                }
            }
        }

        auto res = dp.back()[0];

        for (auto c = 1; c < 26; c++)
        {
            res = std::min(res, dp.back()[c]);
        }

        return res;
    }
};