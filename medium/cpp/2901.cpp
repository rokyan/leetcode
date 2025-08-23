// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

class Solution
{
public:
    std::vector<std::string> getWordsInLongestSubsequence(
        const std::vector<std::string>& words, const std::vector<int>& groups)
    {
        const auto n = std::size(words);
        std::vector<int> dp(n, 1);
        std::vector<int> prev(n, -1);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < i; j++)
            {
                if (dist(words[i], words[j]) == 1 && groups[i] != groups[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        prev[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        auto idx = 0;

        for (auto i = 0; i < n; i++)
        {
            if (dp[i] > dp[idx])
            {
                idx = i;
            }
        }

        std::vector<std::string> res;
        res.reserve(n);

        while (idx != -1)
        {
            res.push_back(words[idx]);
            idx = prev[idx];
        }

        std::ranges::reverse(res);

        return res;
    }

private:
    int dist(const std::string& x, const std::string& y)
    {
        if (std::size(x) != std::size(y))
        {
            return -1;
        }

        const auto n = std::size(x);
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (x[i] != y[i])
            {
                res++;
            }

            if (res == 2)
            {
                break;
            }
        }

        return res;
    }
};