// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/

class Solution
{
public:
    long long minCost(const std::string& s, const std::vector<int>& cost)
    {
        std::array<long long, 26> sum;
        sum.fill(0);

        long long total = 0LL;

        for (int i = 0; i < std::size(s); i++)
        {
            sum[s[i] - 'a'] += cost[i];
            total += cost[i];
        }

        std::optional<long long> res;

        for (int i = 0; i < 26; i++)
        {
            if (sum[i] > 0)
            {
                const long long cur = total - sum[i];

                if (res)
                {
                    res = std::min(res.value(), cur);
                }
                else
                {
                    res = cur;
                }
            }
        }

        return res.value();
    }
};