// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/

class Solution
{
public:
    int maximumTastiness(std::vector<int>& price, int k)
    {
        std::sort(std::begin(price), std::end(price));

        auto lo = 0;
        auto hi = price.back() - price.front() + 1;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (check(price, mid, k))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo - 1;
    }

 private:
    bool check(const std::vector<int>& price, int value, int k) const
    {
        auto last = 0;

        for (auto i = 1; i < std::size(price) && k > 1; i++)
        {
            if (price[i] - price[last] >= value)
            {
                k--;
                last = i;
            }
        }

        return (k == 1);
    }
};  