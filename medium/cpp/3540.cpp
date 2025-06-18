// https://leetcode.com/problems/minimum-time-to-visit-all-houses/description/

class Solution
{
public:
    long long minTotalTime(
        const std::vector<int>& forward,
        const std::vector<int>& backward,
        const std::vector<int>& queries)
    {
        const int n = std::size(forward);

        std::vector<long long> pf(n);

        for (auto i = 1; i < n; i++)
        {
            pf[i] = forward[i - 1] + pf[i - 1];
        }

        std::vector<long long> pb(n);

        for (auto i = n - 2; i >= 0; i--)
        {
            pb[i] = backward[i + 1] + pb[i + 1];
        }

        auto res = 0LL;
        auto cur = 0;

        for (auto i = 0; i < std::size(queries); i++)
        {
            auto next = queries[i];
            auto add = 0;

            if (cur < next)
            {
                auto d = pf[next] - pf[cur];
                auto d2 = pb[0] - pb[cur] + pb[next] + backward[0];
                res += std::min(d, d2);
            }
            else // cur > next
            {
                auto d = pb[next] - pb[cur];
                auto d2 = pf[n - 1] - pf[cur] + pf[next] + forward[n - 1];
                res += std::min(d, d2);
            }

            cur = next;
        }

        return res;
    }
};