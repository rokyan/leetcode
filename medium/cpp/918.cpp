// https://leetcode.com/problems/maximum-sum-circular-subarray/description/

class Solution
{
public:
    int maxSubarraySumCircular(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> suff(n);

        for (auto i = static_cast<int>(n) - 1, s = 0; i >= 0; i--)
        {
            s += nums[i];
            suff[i] = s;

            if (i + 1 < n)
            {
                suff[i] = std::max(suff[i], suff[i + 1]);
            }
        }

        auto res = nums[0];

        for (auto i = 0, pref = 0, s = 0; i < n; i++)
        {
            s += nums[i];
            res = std::max(res, s - pref);
            pref = std::min(pref, s);

            if (i + 1 < n)
            {
                res = std::max(res, s + std::max(0, suff[i + 1]));
            }
        }

        return res;
    }
};