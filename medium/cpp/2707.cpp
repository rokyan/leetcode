// https://leetcode.com/problems/extra-characters-in-a-string/description/

class Solution
{
public:
    int minExtraChar(string s, std::vector<std::string>& dictionary)
    {
        const auto n = std::size(s);

        std::vector<int> dp(n);

        for (auto i = 0; i < n; i++)
        {
            dp[i] = i > 0 ? dp[i - 1] + 1 : 1;

            for (const auto& word : dictionary)
            {
                const auto len = std::size(word);

                if (len <= i + 1 && std::string_view(s).substr(i - len + 1, len) == word)
                {
                    dp[i] = std::min(dp[i], i + 1 == len ? 0 : dp[i - len]);
                }
            }
        }

        return dp.back();
    }
};