// https://leetcode.com/problems/maximize-the-minimum-powered-city/description/

class Solution
{
public:
    long long maxPower(const std::vector<int>& stations, int r, int k)
    {
        long long lo = 0;
        long long hi = 1000'000'000'000'000LL;

        while (lo < hi)
        {
            const long long mid = lo + (hi - lo + 1) / 2;

            if (solve(stations, r, k, mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }

private:
    bool solve(const std::vector<int>& stations, int r, int k, long long expected)
    {
        const int n = stations.size();

        long long sum = 0;

        std::queue<std::pair<int, long long>> additions;

        for (int i = 0, left = 0, right = 0; i < n; i++)
        {
            while (right < std::min(n, i + r + 1))
            {
                sum += stations[right++];
            }

            while (left < i - r)
            {
                if (!additions.empty() && additions.front().first == left)
                {
                    sum -= additions.front().second;
                    additions.pop();
                }

                sum -= stations[left++];
            }

            if (sum < expected)
            {
                const long long add = expected - sum;

                if (add > k)
                {
                    return false;
                }

                k -= add;

                additions.push({std::min(n - 1, i + r), add});
                sum += add;
            }
        }

        return true;
    }
};