// https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/

class Solution
{
public:
    int minimumBeautifulSubstrings(std::string s)
    {
        std::vector<std::string> pows;

        for (auto p = 0, b = 1; p <= 6; p++, b *= 5)
        {
            auto num = b;
            std::string repr;

            while (num > 0)
            {
                repr.push_back('0' + (num % 2 == 1));
                num /= 2;
            }

            std::reverse(std::begin(repr), std::end(repr));

            pows.push_back(repr);
        }

        std::vector<int> dp(std::size(s) + 1, -1);
        dp[0] = 0;

        for (auto i = 1; i <= std::size(s); i++)
        {
            for (const auto& pow : pows)
            {
                const auto len = std::size(pow);

                if (len <= i && dp[i - len] != -1 && s.substr(i - len, len) == pow)
                {
                    if (dp[i] == -1)
                    {
                        dp[i] = dp[i - len] + 1;
                    }
                    else
                    {
                        dp[i] = std::min(dp[i], dp[i - len] + 1);
                    }
                }
            }
        }

        return dp.back();
    }
};