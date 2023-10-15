// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution
{
public:
    int shipWithinDays(std::vector<int>& weights, int days)
    {
        auto lo = *std::max_element(std::cbegin(weights), std::cend(weights));
        auto hi = std::accumulate(std::cbegin(weights), std::cend(weights), 0);

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto cnt = 1;

            for (auto i = 0, rem = mid; i < std::size(weights); i++)
            {
                if (rem < weights[i])
                {
                    rem = mid;
                    cnt++;
                }

                rem -= weights[i];
            }

            if (cnt <= days)
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