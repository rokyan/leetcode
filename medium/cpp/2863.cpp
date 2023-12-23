// https://leetcode.com/problems/maximum-length-of-semi-decreasing-subarrays/description/

class Solution
{
public:
    int maxSubarrayLength(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<std::pair<int, int>> nwp(n);

        for (auto i = 0; i < n; i++)
        {
            nwp[i] = { nums[i], i };
        }

        std::sort(std::begin(nwp), std::end(nwp), std::greater<>{});

        auto mp = n;
        auto res = 0;

        for (auto i = 0; i < n; )
        {
            auto j = i;

            while (j + 1 < n && nwp[j + 1].first == nwp[j].first)
            {
                j++;
            }

            for (auto k = i; k <= j; k++)
            {
                if (mp < nwp[k].second)
                {
                    res = std::max<int>(res, nwp[k].second - mp + 1);
                }
            }

            for (auto k = i; k <= j; k++)
            {
                mp = std::min<int>(mp, nwp[k].second);
            }

            i = j + 1;
        }

        return res;
    }
};