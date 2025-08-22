// https://leetcode.com/problems/distribute-candies-among-children-ii/description/

class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        auto res = 0LL;

        for (auto first = 0; first <= std::min(limit, n); first++)
        {
            const auto rem = n - first;
            const auto start = std::max(rem - limit, 0);
            const auto end = std::min(limit, rem);

            if (end >= start)
            {
                res += end - start + 1;
            }
        }

        return res;
    }
};