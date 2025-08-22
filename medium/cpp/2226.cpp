// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

class Solution
{
public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        const auto n = std::size(candies);
        
        const auto total = std::accumulate(std::cbegin(candies), std::cend(candies), 0LL);

        if (total < k)
        {
            return 0;
        }

        auto lo = 0LL;
        auto hi = total;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;
            auto take = 0LL;

            for (auto i = 0; i < n && take < k; i++)
            {
                take += candies[i] / mid;
            }

            if (take >= k)
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
};