// https://leetcode.com/problems/minimum-average-difference/description/

class Solution
{
public:
    int minimumAverageDifference(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));
        auto s = std::accumulate(std::begin(nums), std::end(nums), 0LL);

        auto ad = s / n;
        auto idx = n - 1;
        auto le = 0LL;

        for (auto i = 0; i + 1 < n; i++)
        {
            s -= nums[i];
            le += nums[i];

            const auto v = std::abs(le / (i + 1) - s / (n - i - 1));

            if (v < ad || v == ad && i < idx)
            {
                ad = v;
                idx = i;
            }
        }

        return idx;
    }
};