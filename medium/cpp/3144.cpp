// https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/description/

class Solution
{
public:
    int minimumSubstringsInPartition(const std::string& s)
    {
        const auto n = std::size(s);

        std::vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (auto i = 0; i < n; i++)
        {
            std::array<int, 26> freq{ 0 };

            for (auto j = i; j >= 0; j--)
            {
                freq[s[j] - 'a']++;

                auto valid = true;
                auto first = -1;

                for (auto c = 0; c < 26 && valid; c++)
                {
                    if (freq[c])
                    {
                        if (first == -1)
                        {
                            first = c;
                        }
                        else
                        {
                            valid &= freq[first] == freq[c];
                        }
                    }
                }

                if (valid)
                {
                    dp[i + 1] = std::min(dp[i + 1], 1 + dp[j]);
                }
            }
        }

        return dp.back();
    }
};