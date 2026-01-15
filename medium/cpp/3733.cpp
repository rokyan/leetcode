// https://leetcode.com/problems/minimum-time-to-complete-all-deliveries/description/

class Solution
{
public:
    long long minimumTime(const std::vector<int>& d, const std::vector<int>& r)
    {
        long long lo = 0LL;
        long long hi = 1000'000'000'000'000;

        while (lo < hi)
        {
            const long long mid = lo + (hi - lo) / 2;

            const long long none = mid / lcm(r[0], r[1]);

            const long long only_first = mid / r[1] - none;
            const long long only_second = mid / r[0] - none;

            const long long rem_first = std::max(0LL, d[0] - only_first);
            const long long rem_second = std::max(0LL, d[1] - only_second);

            if (rem_first + rem_second <= mid - none - only_first - only_second)
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

private:
    long long gcd(long long x, long long y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }

    long long lcm(long long x, long long y)
    {
        return x * y / gcd(x, y);
    }
};