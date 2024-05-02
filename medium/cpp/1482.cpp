// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution
{
public:
    int minDays(std::vector<int>& bloomDay, int m, int k)
    {
        if (std::size(bloomDay) < 1LL * m * k)
        {
            return -1;
        }

        auto lo = 1;
        auto hi = *std::max_element(std::cbegin(bloomDay), std::cend(bloomDay));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            auto cnt = 0;

            for (auto i = 0, adj = 0; i < std::size(bloomDay) && cnt < m; i++)
            {
                if (bloomDay[i] <= mid)
                {
                    if (++adj == k)
                    {
                        adj = 0;
                        cnt++;
                    }
                }
                else
                {
                    adj = 0;
                }
            }

            if (cnt == m)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};