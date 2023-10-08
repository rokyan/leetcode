// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

class Solution
{
public:
    long long minimumTime(std::vector<int>& time, int totalTrips)
    {
        auto lo = 0LL;
        auto hi = 1LL * (*std::max_element(std::begin(time), std::end(time))) * totalTrips;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            auto cnt = 0LL;

            for (auto&& t : time)
            {
                cnt += mid / t;
            }

            if (cnt >= totalTrips)
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