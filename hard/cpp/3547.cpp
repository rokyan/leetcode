// https://leetcode.com/problems/maximum-sum-of-edge-values-in-a-graph/description/

class Solution
{
public:
    long long maxScore(int n, const std::vector<std::vector<int>>& edges)
    {
        std::vector<int> scores(n);

        auto i = n / 2;
        auto j = i - 1;
        auto who = 1;

        for (auto score = n; score > 0; score--)
        {
            if (who)
            {
                scores[i++] = score;
            }
            else
            {
                scores[j--] = score;
            }

            who ^= 1;
        }

        auto res = 0LL;

        for (auto i = 1; i < n; i++)
        {
            res += 1LL * scores[i] * scores[i - 1];
        }

        if (std::size(edges) == n)
        {
            res += 1LL * scores[0] * scores[n - 1];
        }

        return res;
    }
};