// https://leetcode.com/problems/find-maximum-number-of-non-intersecting-substrings/description/

class Solution
{
public:
    int maxSubstrings(const std::string& word)
    {
        std::vector<std::deque<int>> pos(26);
        std::vector<int> dp(std::size(word));
        auto res = 0;

        for (auto i = 0; i < std::size(word); i++)
        {
            const auto c = word[i] - 'a';

            if (i > 0)
            {
                dp[i] = dp[i - 1];
            }

            while (std::size(pos[c]) > 0 && i - pos[c].front() + 1 >= 4)
            {
                dp[i] = std::max(dp[i], 1 + (pos[c].front() > 0 ? dp[pos[c].front() - 1] : 0));
                pos[c].pop_front();
            }

            pos[c].push_back(i);

            res = std::max(res, dp[i]);
        }

        return res;
    }
};